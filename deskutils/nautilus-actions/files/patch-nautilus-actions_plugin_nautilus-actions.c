--- nautilus-actions/plugin/nautilus-actions.c.orig	2010-01-03 00:33:06.000000000 -0500
+++ nautilus-actions/plugin/nautilus-actions.c	2010-01-03 00:33:41.000000000 -0500
@@ -468,7 +468,7 @@ is_action_candidate( NautilusActions *pl
 {
 	static const gchar *thisfn = "nautilus_actions_is_action_candidate";
 	NAObjectProfile *candidate = NULL;
-	gchar *action_label;
+	gchar *action_label = NULL;
 	gchar *profile_label;
 	GList *profiles, *ip;
 
