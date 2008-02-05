--- src/ck-sysdeps-freebsd.c.orig        2008-01-23 09:30:44.000000000 -0500
+++ src/ck-sysdeps-freebsd.c        2008-02-04 19:32:33.000000000 -0500
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
 
@@ -319,8 +321,10 @@ ck_get_max_num_consoles (guint *num)
 {
         int      max_consoles;
         int      res;
+        int      fd;
         gboolean ret;
         struct ttyent *t;
+        char    *cdev;
 
         ret = FALSE;
         max_consoles = 0;
@@ -331,9 +335,28 @@ ck_get_max_num_consoles (guint *num)
         }
 
         while ((t = getttyent ()) != NULL) {
-                if (t->ty_status & TTY_ON && strncmp (t->ty_name, "ttyv", 4) == 0)
-                        max_consoles++;
-        }
+                if (t->ty_status & TTY_ON && strncmp (t->ty_name, "ttyv", 4) == 0) {
+                        cdev = g_strdup_printf ("/dev/%s", t->ty_name);
+
+                        fd = open (cdev, O_RDONLY | O_NOCTTY);
+                        if (fd > -1) {
+                                close (fd);
+                                max_consoles++;
+                        }
+                        g_free (cdev);
+                }
+        }
+
+        if (max_consoles < MAXCONS) {
+                /* We do this once more to have a console for X sessions. */
+                cdev = g_strdup_printf ("/dev/ttyv%i", max_consoles);
+                fd = open (cdev, O_RDONLY | O_NOCTTY);
+                if (fd > -1) {
+                        max_consoles++;
+                        close (fd);
+                }
+                g_free (cdev);
+        }
 
         /* Increment one more so that all consoles are properly counted
          * this is arguable a bug in vt_add_watches().
