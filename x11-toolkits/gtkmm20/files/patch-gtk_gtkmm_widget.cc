--- gtk/gtkmm/widget.cc.orig	Thu Dec 11 16:17:47 2003
+++ gtk/gtkmm/widget.cc	Thu Dec 11 16:18:37 2003
@@ -114,22 +114,22 @@
 
 void Widget::unset_fg(StateType state)
 {
-  gtk_widget_modify_fg(gobj(), static_cast<GtkStateType>(state), 0);
+  gtk_widget_modify_fg(gobj(), (GtkStateType)(state), 0);
 }
 
 void Widget::unset_bg(StateType state)
 {
-  gtk_widget_modify_bg(gobj(), static_cast<GtkStateType>(state), 0);
+  gtk_widget_modify_bg(gobj(), (GtkStateType)(state), 0);
 }
 
 void Widget::unset_text(StateType state)
 {
-  gtk_widget_modify_text(gobj(), static_cast<GtkStateType>(state), 0);
+  gtk_widget_modify_text(gobj(), (GtkStateType)(state), 0);
 }
 
 void Widget::unset_base(StateType state)
 {
-  gtk_widget_modify_base(gobj(), static_cast<GtkStateType>(state), 0);
+  gtk_widget_modify_base(gobj(), (GtkStateType)(state), 0);
 }
 
 void Widget::unset_font()
