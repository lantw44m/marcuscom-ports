--- src/nautilus-image-properties-page.c.orig	Wed Nov 24 13:25:51 2004
+++ src/nautilus-image-properties-page.c	Wed Nov 24 13:26:28 2004
@@ -144,13 +144,14 @@
 exif_content_callback (ExifContent *content, gpointer data)
 {
 	struct ExifAttribute *attribute;
+	char value[1024];
 
 	attribute = (struct ExifAttribute *)data;
 	if (attribute->found) {
 		return;
 	}
 
-        attribute->value = g_strdup (exif_content_get_value (content, attribute->tag));
+        attribute->value = g_strdup (exif_content_get_value (content, attribute->tag, value, sizeof(value)));
 	if (attribute->value != NULL) {
 		attribute->found = TRUE;
 	}
