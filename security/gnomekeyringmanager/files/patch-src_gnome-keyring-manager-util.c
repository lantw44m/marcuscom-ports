--- src/gnome-keyring-manager-util.c.orig	Thu Mar 31 14:27:56 2005
+++ src/gnome-keyring-manager-util.c	Thu Mar 31 14:28:26 2005
@@ -276,8 +276,6 @@ gkm_about_dialog_new (GtkWindow *transie
 {
   GtkWidget *about;
 
-  g_return_val_if_fail (GTK_IS_WINDOW (transient_parent), NULL);
-
   const char *authors[] = {
     "Fernando Herrera <fherrera@onirica.com>",
     "Mariano Su\303\241rez-Alvarez <mariano@gnome.org>",
@@ -288,6 +286,8 @@ gkm_about_dialog_new (GtkWindow *transie
   const char *documenters[] = {
     NULL
   };
+
+  g_return_val_if_fail (GTK_IS_WINDOW (transient_parent), NULL);
 
   gtk_about_dialog_set_email_hook ((GtkAboutDialogActivateLinkFunc) gkm_about_dialog_activate_links,
 				   GINT_TO_POINTER (LINK_TYPE_EMAIL), NULL);
