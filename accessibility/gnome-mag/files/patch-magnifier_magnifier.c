--- magnifier/magnifier.c.orig	2010-03-13 22:53:14.000000000 +0100
+++ magnifier/magnifier.c	2010-03-13 22:57:27.000000000 +0100
@@ -894,7 +894,7 @@ magnifier_reset_struts_at_idle (gpointer
 	{
 		Magnifier *magnifier = MAGNIFIER (data);
 		if (magnifier->priv &&
-		    GTK_WIDGET_REALIZED (magnifier->priv->w) && 
+		    gtk_widget_get_realized (magnifier->priv->w) && 
 		    gmag_gs_check_set_struts (magnifier)) {
 			return FALSE;
 		}
