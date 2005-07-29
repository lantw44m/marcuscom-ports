--- plugins/groupwise-features/proxy.c.orig	Fri Jul 29 18:53:05 2005
+++ plugins/groupwise-features/proxy.c	Fri Jul 29 18:53:27 2005
@@ -671,8 +671,8 @@ org_gnome_proxy (EPlugin *epl, EConfigHo
 		prd = g_object_get_data ((GObject *) account, "prd");
 
 		if (prd) {
-			priv = prd->priv;
 			int pag_num;
+			priv = prd->priv;
 			if (priv) {
 			pag_num = gtk_notebook_page_num ( (GtkNotebook *)(data->parent), (GtkWidget *) priv->tab_dialog);
 			gtk_notebook_remove_page ( (GtkNotebook *)(data->parent), pag_num); 
