--- capplets/keyboard/gnome-keyboard-properties-xkbot.c.orig	Sun May 22 22:57:24 2005
+++ capplets/keyboard/gnome-keyboard-properties-xkbot.c	Sun May 22 22:58:27 2005
@@ -243,11 +243,12 @@ xkb_options_add_group (const XklConfigIt
                                          GladeXML * dialog)
 {
   GtkWidget *expander, *align, *vbox;
+  gchar *utfGroupName, *titlemarkup;
 
   GSList * expanders_list = g_object_get_data (G_OBJECT (dialog), EXPANDERS_PROP);
 
-  gchar *utfGroupName = xci_desc_to_utf8 (configItem);
-  gchar *titlemarkup = g_strconcat ("<span>", utfGroupName, "</span>", NULL);
+  utfGroupName = xci_desc_to_utf8 (configItem);
+  titlemarkup = g_strconcat ("<span>", utfGroupName, "</span>", NULL);
 
   expander = gtk_expander_new (titlemarkup);
   g_object_set_data_full (G_OBJECT (expander), "utfGroupName", utfGroupName, g_free);
