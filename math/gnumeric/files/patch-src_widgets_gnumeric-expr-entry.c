--- src/widgets/gnumeric-expr-entry.c	2007/06/18 15:49:42	15609
+++ src/widgets/gnumeric-expr-entry.c	2007/06/18 17:17:20	15610
@@ -176,14 +176,14 @@
 			g_assert (GTK_IS_CONTAINER (old_entry_parent));
 
 			g_object_set_data_full (G_OBJECT (entry), "old_entry_parent",
-						gtk_widget_ref (old_entry_parent),
-						(GDestroyNotify) gtk_widget_unref);
+						g_object_ref (old_entry_parent),
+						(GDestroyNotify) g_object_unref);
 
 			g_return_if_fail ((GtkWidget *) entry != old_toplevel_child);
 
 			g_object_set_data_full (G_OBJECT (entry), "old_toplevel_child",
-						gtk_widget_ref (old_toplevel_child),
-						(GDestroyNotify) gtk_widget_unref);
+						g_object_ref (old_toplevel_child),
+						(GDestroyNotify) g_object_unref);
 
 			gtk_window_get_size (GTK_WINDOW (toplevel), &width, &height);
 			g_object_set_data (G_OBJECT (entry), "old_window_width", GUINT_TO_POINTER (width));
@@ -234,11 +234,11 @@
 			old_entry_parent = g_object_get_data (G_OBJECT (entry), "old_entry_parent");
 			g_assert (GTK_IS_CONTAINER (old_entry_parent));
 
-			gtk_widget_ref (GTK_WIDGET (entry));
+			g_object_ref (entry);
 			gtk_container_remove (GTK_CONTAINER (toplevel), GTK_WIDGET (entry));
 			gtk_container_add (GTK_CONTAINER (toplevel), old_toplevel_child);
 			gtk_container_add (GTK_CONTAINER (old_entry_parent), GTK_WIDGET (entry));
-			gtk_widget_unref (GTK_WIDGET (entry));
+			g_object_unref (entry);
 
 			container_props = g_object_get_data (G_OBJECT (entry), "container_props");
 			container_props_pspec = g_object_get_data (G_OBJECT (entry), "container_props_pspec");
