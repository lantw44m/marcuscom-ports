--- gio/fam/fam-helper.c.orig	2008-01-10 19:33:27.000000000 +0100
+++ gio/fam/fam-helper.c	2008-01-10 19:31:55.000000000 +0100
@@ -82,7 +82,7 @@ fam_do_iter_unlocked (void)
     cancelled = sub->cancelled;
     if (ev.code == FAMAcknowledge && cancelled)
       {
-	g_free (sub);
+	_fam_sub_free (sub);
 	continue;
       }
     
