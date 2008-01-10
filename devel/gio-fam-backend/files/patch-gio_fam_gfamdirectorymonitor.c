--- gio/fam/gfamdirectorymonitor.c.orig	2008-01-07 15:15:54.000000000 +0100
+++ gio/fam/gfamdirectorymonitor.c	2008-01-10 19:38:08.000000000 +0100
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
 
