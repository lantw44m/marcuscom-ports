--- sys/v4l/v4lsrc_calls.c.orig	2008-02-23 14:41:56.000000000 -0500
+++ sys/v4l/v4lsrc_calls.c	2008-02-23 15:52:06.000000000 -0500
@@ -26,12 +26,14 @@
 
 #include <stdlib.h>
 #include <sys/types.h>
+#include <sys/uio.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
 #include <string.h>
 #include <errno.h>
+#include <unistd.h>
 #include "v4lsrc_calls.h"
 #include <sys/time.h>
 
@@ -87,6 +89,15 @@ gst_v4lsrc_queue_frame (GstV4lSrc * v4ls
     return FALSE;
   }
 
+  if (GST_V4LELEMENT (v4lsrc)->use_read) {
+    if (read(GST_V4LELEMENT (v4lsrc)->video_fd, GST_V4LELEMENT (v4lsrc)->buffer, v4lsrc->mmap.width * v4lsrc->mmap.height * 3/2) < 0) {
+      GST_ELEMENT_ERROR (v4lsrc, RESOURCE, WRITE, (NULL),
+          ("Error queueing a buffer (%d): %s", num, g_strerror (errno)));
+      return FALSE;
+    }
+    goto done;
+  }
+
   /* instruct the driver to prepare capture using buffer frame num */
   v4lsrc->mmap.frame = num;
   if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd,
@@ -95,6 +106,7 @@ gst_v4lsrc_queue_frame (GstV4lSrc * v4ls
         ("Error queueing a buffer (%d): %s", num, g_strerror (errno)));
     return FALSE;
   }
+done:
 
   v4lsrc->frame_queue_state[num] = QUEUE_STATE_QUEUED;
   v4lsrc->num_queued++;
@@ -168,13 +180,23 @@ gst_v4lsrc_capture_init (GstV4lSrc * v4l
   GST_V4L_CHECK_OPEN (GST_V4LELEMENT (v4lsrc));
   GST_V4L_CHECK_NOT_ACTIVE (GST_V4LELEMENT (v4lsrc));
 
+  GST_V4LELEMENT (v4lsrc)->use_read = FALSE;
+
   /* request the mmap buffer info:
    * total size of mmap buffer, number of frames, offsets of frames */
   if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCGMBUF,
           &(v4lsrc->mbuf)) < 0) {
     GST_ELEMENT_ERROR (v4lsrc, RESOURCE, READ, (NULL),
-        ("Error getting buffer information: %s", g_strerror (errno)));
-    return FALSE;
+        ("Error getting buffer information: %s, trying with read", g_strerror (errno)));
+    GST_V4LELEMENT (v4lsrc)->buffer = (guint8 *) g_malloc0 (sizeof (guint8) * 1024 * 768 * 3);
+    GST_V4LELEMENT (v4lsrc)->use_read = TRUE;
+
+    v4lsrc->frame_queue_state = (gint8 *) g_malloc (sizeof (gint8) * (768 * 3));
+
+    /* lock for the frame_state */
+    v4lsrc->mutex_queue_state = g_mutex_new ();
+    v4lsrc->cond_queue_state = g_cond_new ();
+    goto done;
   }
 
   if (v4lsrc->mbuf.frames < MIN_BUFFERS_QUEUED) {
@@ -205,6 +227,7 @@ gst_v4lsrc_capture_init (GstV4lSrc * v4l
     GST_V4LELEMENT (v4lsrc)->buffer = NULL;
     return FALSE;
   }
+done:
 
   return TRUE;
 }
@@ -413,10 +436,14 @@ gst_v4lsrc_capture_deinit (GstV4lSrc * v
   v4lsrc->frame_queue_state = NULL;
 
   /* unmap the buffer */
-  if (munmap (GST_V4LELEMENT (v4lsrc)->buffer, v4lsrc->mbuf.size) == -1) {
-    GST_ELEMENT_ERROR (v4lsrc, RESOURCE, CLOSE, (NULL),
-        ("error munmap'ing capture buffer: %s", g_strerror (errno)));
-    return FALSE;
+  if (GST_V4LELEMENT (v4lsrc)->use_read) {
+    g_free (GST_V4LELEMENT (v4lsrc)->buffer);
+  } else {
+    if (munmap (GST_V4LELEMENT (v4lsrc)->buffer, v4lsrc->mbuf.size) == -1) {
+      GST_ELEMENT_ERROR (v4lsrc, RESOURCE, CLOSE, (NULL),
+          ("error munmap'ing capture buffer: %s", g_strerror (errno)));
+      return FALSE;
+    }
   }
   GST_V4LELEMENT (v4lsrc)->buffer = NULL;
 
@@ -446,6 +473,7 @@ gst_v4lsrc_try_capture (GstV4lSrc * v4ls
   /* so, we need a buffer and some more stuff */
   int frame = 0;
   guint8 *buffer;
+  gboolean use_read = FALSE;
   struct video_mbuf vmbuf;
   struct video_mmap vmmap;
 
@@ -457,16 +485,18 @@ gst_v4lsrc_try_capture (GstV4lSrc * v4ls
   /* let's start by requesting a buffer and mmap()'ing it */
   if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCGMBUF, &vmbuf) < 0) {
     GST_ELEMENT_ERROR (v4lsrc, RESOURCE, READ, (NULL),
-        ("Error getting buffer information: %s", g_strerror (errno)));
-    return FALSE;
-  }
-  /* Map the buffers */
-  buffer = mmap (0, vmbuf.size, PROT_READ | PROT_WRITE,
-      MAP_SHARED, GST_V4LELEMENT (v4lsrc)->video_fd, 0);
-  if (buffer == MAP_FAILED) {
-    GST_ELEMENT_ERROR (v4lsrc, RESOURCE, OPEN_READ_WRITE, (NULL),
-        ("Error mapping our try-out buffer: %s", g_strerror (errno)));
-    return FALSE;
+        ("Error getting buffer information: %s, trying read", g_strerror (errno)));
+    buffer = (gint8 *) g_malloc0 (sizeof (gint8) * 1024 * 768 * 3);
+    use_read = TRUE;
+  } else {
+    /* Map the buffers */
+    buffer = mmap (0, vmbuf.size, PROT_READ | PROT_WRITE,
+        MAP_SHARED, GST_V4LELEMENT (v4lsrc)->video_fd, 0);
+    if (buffer == MAP_FAILED) {
+      GST_ELEMENT_ERROR (v4lsrc, RESOURCE, OPEN_READ_WRITE, (NULL),
+          ("Error mapping our try-out buffer: %s", g_strerror (errno)));
+      return FALSE;
+    }
   }
 
   /* now that we have a buffer, let's try out our format */
@@ -474,6 +504,15 @@ gst_v4lsrc_try_capture (GstV4lSrc * v4ls
   vmmap.height = height;
   vmmap.format = palette;
   vmmap.frame = frame;
+  if (use_read) {
+    if (read (GST_V4LELEMENT (v4lsrc)->video_fd, buffer, width * height * 3/2) < 0) {
+      GST_ERROR_OBJECT (v4lsrc,
+           "Error reading into our ty-out buffer: %s", g_strerror (errno));
+      g_free (buffer);
+      return FALSE;
+    }
+    goto done;
+  }
   if (ioctl (GST_V4LELEMENT (v4lsrc)->video_fd, VIDIOCMCAPTURE, &vmmap) < 0) {
     if (errno != EINVAL)        /* our format failed! */
       GST_ERROR_OBJECT (v4lsrc,
@@ -488,7 +527,11 @@ gst_v4lsrc_try_capture (GstV4lSrc * v4ls
     return FALSE;
   }
 
-  munmap (buffer, vmbuf.size);
+done:
+  if (use_read)
+    g_free (buffer);
+  else
+    munmap (buffer, vmbuf.size);
 
   /* if we got here, it worked! woohoo, the format is supported! */
   return TRUE;
