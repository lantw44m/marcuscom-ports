--- gtk/src/jni/org_gnu_gtk_ActionGroup.c.orig	Mon Jan  5 13:09:08 2004
+++ gtk/src/jni/org_gnu_gtk_ActionGroup.c	Mon Jan  5 13:09:35 2004
@@ -76,11 +76,13 @@
   (JNIEnv *env, jclass cls, jint group)
 {
 	GList *list = gtk_action_group_list_actions((GtkActionGroup*)group);
+	guint len;
+	jintArray ar;
+	int i = 0;
 	if (NULL == list)
 		return NULL;
-	 guint len = g_list_length(list);
-	 jintArray ar = (*env)->NewIntArray(env, len);
-	 int i = 0;
+	 len = g_list_length(list);
+	 ar = (*env)->NewIntArray(env, len);
 	for (i = 0; i < len; i++) {
 		GList *item = g_list_nth(list, i);
 		(*env)->SetIntArrayRegion(env, ar, i, 1, (jint*)item->data);
