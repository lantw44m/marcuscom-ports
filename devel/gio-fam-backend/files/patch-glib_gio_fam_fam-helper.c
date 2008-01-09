--- glib/gio/fam/fam-helper.c.orig	2008-01-09 01:32:59.000000000 -0500
+++ glib/gio/fam/fam-helper.c	2008-01-09 01:33:15.000000000 -0500
@@ -82,7 +82,7 @@ fam_do_iter_unlocked (void)
     cancelled = sub->cancelled;
     if (ev.code == FAMAcknowledge && cancelled)
       {
-	g_free (sub);
+	_fam_sub_free (sub);
 	continue;
       }
     
