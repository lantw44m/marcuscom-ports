--- glib/gio/fam/gfamdirectorymonitor.c.orig	2008-01-09 01:33:43.000000000 -0500
+++ glib/gio/fam/gfamdirectorymonitor.c	2008-01-09 01:33:53.000000000 -0500
@@ -50,7 +50,6 @@ g_fam_directory_monitor_finalize (GObjec
     if (!_fam_sub_cancel (sub))
       g_warning ("Unexpected error cancelling fam monitor");
 
-    _fam_sub_free (sub);
     fam_monitor->sub = NULL;
   }
 
@@ -134,7 +133,6 @@ g_fam_directory_monitor_cancel (GFileMon
     if (!_fam_sub_cancel (sub))
       g_warning ("Unexpected error cancelling fam monitor");
 
-    _fam_sub_free (sub);
     fam_monitor->sub = NULL;
   }
 
