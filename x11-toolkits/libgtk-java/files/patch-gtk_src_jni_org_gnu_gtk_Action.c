--- gtk/src/jni/org_gnu_gtk_Action.c.orig	Mon Jan  5 13:06:32 2004
+++ gtk/src/jni/org_gnu_gtk_Action.c	Mon Jan  5 13:07:18 2004
@@ -115,11 +115,13 @@
   (JNIEnv *env, jclass cls, jint action)
 {
 	GSList *list = gtk_action_get_proxies((GtkAction*)action);
+	guint len;
+	jintArray ar;
+	int i = 0;
 	if (NULL == list)
 		return NULL;
-	 guint len = g_slist_length(list);
-	 jintArray ar = (*env)->NewIntArray(env, len);
-	 int i = 0;
+	 len = g_slist_length(list);
+	 ar = (*env)->NewIntArray(env, len);
 	for (i = 0; i < len; i++) {
 		GSList *item = g_slist_nth(list, i);
 		(*env)->SetIntArrayRegion(env, ar, i, 1, (jint*)item->data);
