--- examples/iconlist/iconlist2.cc.orig	Wed Feb 11 22:27:29 2004
+++ examples/iconlist/iconlist2.cc	Thu Feb 12 02:35:43 2004
@@ -14,7 +14,7 @@
     virtual void on_select_icon(int icon, GdkEvent* event);
     virtual void on_unselect_icon(int icon, GdkEvent* event);
     virtual void on_drag_data_get(const Glib::RefPtr<Gdk::DragContext>& context,
-                                     GtkSelectionData* data,
+                                     Gtk::SelectionData& data,
                                      guint info,
                                      guint time);
     virtual void on_drag_data_delete(const Glib::RefPtr<Gdk::DragContext>& context);
@@ -60,17 +60,14 @@
 
 void 
 TestIconList::on_drag_data_get(const Glib::RefPtr<Gdk::DragContext>& context,
-                                  GtkSelectionData* data,
+                                  Gtk::SelectionData& data,
                                   guint info,
                                   guint time)
 {
     Gnome::UI::IconList::on_drag_data_get(context, data, info, time);
     char* name = (char*) get_icon_data(m_selected);
-    gtk_selection_data_set(data,
-                            data->target,
-                            8, 
-                            (const guchar*) name,
-                            strlen(name));
+    data.set(8,  (guint8*)name, strlen(name));
+    std::cerr << "TestIconList::on_drag_data_get called" << std::endl;
 }
 
 
