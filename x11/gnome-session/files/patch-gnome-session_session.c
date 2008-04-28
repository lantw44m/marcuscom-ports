--- gnome-session/session.c.orig	2008-04-28 13:19:41.000000000 -0400
+++ gnome-session/session.c	2008-04-28 13:17:22.000000000 -0400
@@ -155,6 +155,8 @@ static void
 append_app (GsmSession *session, GsmApp *app)
 {
   const char *basename = gsm_app_get_basename (app);
+  if (!basename)
+    return;
   GsmApp *dup = g_hash_table_lookup (session->apps_by_name, basename);
 
   if (dup)
