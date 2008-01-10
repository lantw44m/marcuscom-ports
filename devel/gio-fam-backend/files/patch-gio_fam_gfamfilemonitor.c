--- gio/fam/gfamfilemonitor.c.orig	2008-01-09 01:34:15.000000000 -0500
+++ gio/fam/gfamfilemonitor.c	2008-01-09 01:34:19.000000000 -0500
@@ -49,7 +49,6 @@ g_fam_file_monitor_finalize (GObject *ob
   if (sub) {
     if (!_fam_sub_cancel (sub))
       g_warning ("Unexpected error cancelling fam monitor");
-    _fam_sub_free (sub);
     fam_monitor->sub = NULL;
   }
 
@@ -132,7 +131,6 @@ g_fam_file_monitor_cancel (GFileMonitor*
   if (sub) {
     if (!_fam_sub_cancel (sub))
       g_warning ("Unexpected error cancelling fam monitor");
-    _fam_sub_free (sub);
     fam_monitor->sub = NULL;
   }
 
