--- profiles/gnome-audio-profiles-properties.c.orig	Mon Sep 20 20:51:20 2004
+++ profiles/gnome-audio-profiles-properties.c	Fri Feb 11 23:40:04 2005
@@ -21,6 +21,9 @@
 
 #include <gtk/gtkmain.h>
 #include "gnome-media-profiles.h"
+#include <glade/glade.h>
+#include <glade/glade-build.h>
+#include <string.h>
 
 static void
 on_dialog_destroy (GtkWidget *dialog, gpointer *user_data)
@@ -29,6 +32,52 @@
   gtk_main_quit ();
 }
 
+static void
+gtk_dialog_build_children(GladeXML *self, GtkWidget *w,
+			  GladeWidgetInfo *info)
+
+{
+    GtkDialog *dialog = GTK_DIALOG (w);
+    GList *children, *list;
+
+    glade_standard_build_children (self, w, info);
+
+    if (dialog->action_area == NULL)
+	return;
+
+    /* repack children of action_area */
+    children = gtk_container_get_children(GTK_CONTAINER(dialog->action_area));
+    for (list = children; list; list = list->next) {
+	GtkWidget *child = GTK_WIDGET(list->data);
+
+	g_object_ref(child);
+	gtk_container_remove (GTK_CONTAINER (dialog->action_area), child);
+    }
+    for (list = children; list; list = list->next) {
+	GtkWidget *child = GTK_WIDGET(list->data);
+	gint response_id;
+
+	response_id = GPOINTER_TO_INT(g_object_steal_data(G_OBJECT(child),
+							  "response_id"));
+	gtk_dialog_add_action_widget(dialog, child, response_id);
+	g_object_unref(child);
+
+    }
+    g_list_free (children);
+}
+
+static GtkWidget *
+dialog_find_internal_child(GladeXML *xml, GtkWidget *parent,
+			   const gchar *childname)
+{
+    if (!strcmp(childname, "vbox"))
+	return GTK_DIALOG(parent)->vbox;
+    if (!strcmp(childname, "action_area"))
+	return GTK_DIALOG(parent)->action_area;
+
+    return NULL;
+}
+
 int
 main (int argc, char *argv[])
 {
@@ -39,6 +88,10 @@
   /* FIXME: add a comment why we need this at all, until then
      we comment it out
   gm_audio_profile_edit_get_type (); */
+  glade_register_widget (gm_audio_profile_edit_get_type (),
+			 NULL,
+			 gtk_dialog_build_children,
+			 dialog_find_internal_child);
   conf = gconf_client_get_default ();
   gnome_media_profiles_init (conf);
 
