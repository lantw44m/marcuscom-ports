--- mail/em-account-editor.c.orig	Tue Dec 21 23:20:28 2004
+++ mail/em-account-editor.c	Tue Dec 21 23:22:33 2004
@@ -188,6 +188,7 @@
 } EMAccountEditorPrivate;
 
 static GtkWidget *emae_setup_authtype(EMAccountEditor *emae, EMAccountEditorService *service);
+static void emae_authtype_changed(GtkComboBox *dropdown, EMAccountEditorService *service);
 
 static GtkVBoxClass *emae_parent;
 
