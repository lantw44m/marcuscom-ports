--- gtk/src/jni/org_gnu_gtk_UIManager.c.orig	Mon Jan  5 13:16:49 2004
+++ gtk/src/jni/org_gnu_gtk_UIManager.c	Mon Jan  5 13:17:13 2004
@@ -92,11 +92,13 @@
   (JNIEnv *env, jclass cls, jint uim)
 {
 	GList *list = gtk_ui_manager_get_action_groups((GtkUIManager*)uim);
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
