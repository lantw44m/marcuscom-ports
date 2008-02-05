--- src/ck-sysdeps-freebsd.c.orig        2008-01-23 09:30:44.000000000 -0500
+++ src/ck-sysdeps-freebsd.c        2008-02-04 20:56:57.000000000 -0500
@@ -43,6 +43,10 @@
   ( (M&0xfff) << 8) | ( (m&0xfff00) << 12) | (m&0xff) \
 )
 
+#ifndef MAXCONS
+#define MAXCONS                16
+#endif
+
 #include "ck-sysdeps.h"
 
 #ifndef ERROR
@@ -202,7 +206,6 @@ ck_process_stat_new_for_unix_pid (pid_t 
                                   GError        **error)
 {
         gboolean       res;
-        GError        *local_error;
         CkProcessStat *proc;
 
         g_return_val_if_fail (pid > 1, FALSE);
@@ -217,7 +220,6 @@ ck_process_stat_new_for_unix_pid (pid_t 
         if (res) {
                 *stat = proc;
         } else {
-                g_propagate_error (error, local_error);
                 *stat = NULL;
         }
 
@@ -318,38 +320,36 @@ gboolean
 ck_get_max_num_consoles (guint *num)
 {
         int      max_consoles;
-        int      res;
-        gboolean ret;
-        struct ttyent *t;
+        int      i;
 
-        ret = FALSE;
-        max_consoles = 0;
-
-        res = setttyent ();
-        if (res == 0) {
-                goto done;
-        }
+        max_consoles = 0;
 
-        while ((t = getttyent ()) != NULL) {
-                if (t->ty_status & TTY_ON && strncmp (t->ty_name, "ttyv", 4) == 0)
-                        max_consoles++;
-        }
+        for (i = 0; i < MAXCONS; i++) {
+                int fd;
+                char *cdev;
+
+                cdev = g_strdup_printf ("/dev/ttyv%x", i);
+                fd = open (cdev, O_RDONLY | O_NOCTTY);
+                g_free (cdev);
+                if (fd > -1) {
+                        close (fd);
+                        max_consoles++;
+                } else {
+                        break;
+                }
+        }
+
+        /*
+         * Increment one more so that all consoles are properly counted
+         * this is arguable a bug in vt_add_watches().
+         */
+        max_consoles++;
 
-        /* Increment one more so that all consoles are properly counted
-         * this is arguable a bug in vt_add_watches().
-         */
-        max_consoles++;
-
-        ret = TRUE;
-
-        endttyent ();
-
-done:
         if (num != NULL) {
                 *num = max_consoles;
         }
 
-        return ret;
+        return TRUE;
 }
 
 char *
@@ -360,7 +360,7 @@ ck_get_console_device_for_num (guint num
         /* The device number is always one less than the VT number. */
         num--;
 
-        device = g_strdup_printf ("/dev/ttyv%u", num);
+        device = g_strdup_printf ("/dev/ttyv%x", num);
 
         return device;
 }
@@ -379,7 +379,7 @@ ck_get_console_num_from_device (const ch
                 return FALSE;
         }
 
-        if (sscanf (device, "/dev/ttyv%u", &n) == 1) {
+        if (sscanf (device, "/dev/ttyv%x", &n) == 1) {
                 /* The VT number is always one more than the device number. */
                 n++;
                 ret = TRUE;
@@ -411,7 +411,7 @@ ck_get_active_console_num (int    consol
                 goto out;
         }
 
-        g_debug ("Active VT is: %d (ttyv%d)", active, active - 1);
+        g_debug ("Active VT is: %d (ttyv%x)", active, active - 1);
         ret = TRUE;
 
  out:
