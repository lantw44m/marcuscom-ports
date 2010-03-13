--- magnifier/x11/gmag-graphical-server.c.orig	2010-03-13 22:53:48.000000000 +0100
+++ magnifier/x11/gmag-graphical-server.c	2010-03-13 22:56:58.000000000 +0100
@@ -159,7 +159,7 @@ gmag_gs_check_set_struts (Magnifier *mag
 #endif
 
 	if (magnifier &&
-	    magnifier->priv && magnifier->priv->w && GTK_WIDGET_REALIZED (magnifier->priv->w) &&
+	    magnifier->priv && magnifier->priv->w && gtk_widget_get_realized (magnifier->priv->w) &&
 	    magnifier->priv->w->window) 
 	{
 		Atom atom_strut = gdk_x11_get_xatom_by_name ("_NET_WM_STRUT");
@@ -249,7 +249,7 @@ gmag_gs_reset_overlay_at_idle (gpointer 
 	if (data) {
 		Magnifier *magnifier = MAGNIFIER (data);
 		if (magnifier->priv && magnifier->priv->w &&
-		    GTK_WIDGET_REALIZED (magnifier->priv->w)) 
+		    gtk_widget_get_realized (magnifier->priv->w)) 
 			if (magnifier->priv->w->window) {
 #ifdef HAVE_OVERLAY
 				gint      x, y, over_w, over_h;
