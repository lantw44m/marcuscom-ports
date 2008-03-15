--- hald/device.c.orig	2008-03-15 19:13:58.000000000 -0400
+++ hald/device.c	2008-03-15 19:14:45.000000000 -0400
@@ -871,7 +871,7 @@ hdpfe (gpointer key,
 {
 	hdpfe_ud_t *c;
 	HalProperty *prop;
-	const gchar *key_string = g_quark_to_string ((GQuark) key);
+	const gchar *key_string = g_quark_to_string ((GQuark) GPOINTER_TO_UINT(key));
 
 	c = (hdpfe_ud_t *) user_data;
 	prop = (HalProperty *) value;
