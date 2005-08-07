--- libgda/gda-value.c.orig	Sun Aug  7 16:57:51 2005
+++ libgda/gda-value.c	Sun Aug  7 16:58:40 2005
@@ -549,10 +549,11 @@ gpointer 
 gda_geometricpoint_copy (gpointer boxed)
 {
 	GdaGeometricPoint *val = (GdaGeometricPoint*) boxed;
+	GdaGeometricPoint *copy;
 	
 	g_return_val_if_fail( val, NULL);
 		
-	GdaGeometricPoint *copy = g_new0(GdaGeometricPoint, 1);
+	copy = g_new0(GdaGeometricPoint, 1);
 	copy->x = val->x;
 	copy->y = val->y;
 
@@ -1260,8 +1261,8 @@ gda_value_is_null (GdaValue *value)
 gboolean
 gda_value_is_number (GdaValue *value)
 {
-	g_return_val_if_fail (value && G_IS_VALUE(value), FALSE);
 	GdaValueType type;
+	g_return_val_if_fail (value && G_IS_VALUE(value), FALSE);
 	
 	type = GDA_VALUE_TYPE(value);
 	switch (type) {
@@ -1406,9 +1407,9 @@ gda_value_get_binary (GdaValue *value, g
 void
 gda_value_set_binary (GdaValue *value, gconstpointer val, glong size)
 {
+	GdaBinary *binary;
 	g_return_if_fail (value);
 	
-	GdaBinary *binary;
 	
 	binary = g_new0 (GdaBinary, 1);
 
@@ -1443,10 +1444,10 @@ gda_value_get_blob (GdaValue *value)
 void
 gda_value_set_blob (GdaValue *value, const GdaBlob *val)
 {
+	GdaBlob *blob;
 	g_return_if_fail (value);
 	g_return_if_fail (GDA_VALUE_IS_BLOB(val));
 	
-	GdaBlob *blob;
 	l_g_value_unset (value);
 	g_value_init (value, G_VALUE_TYPE_BLOB);
 	
