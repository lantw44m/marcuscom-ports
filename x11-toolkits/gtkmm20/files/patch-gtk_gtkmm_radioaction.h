--- gtk/gtkmm/radioaction.h.orig	Sat Nov 29 15:35:00 2003
+++ gtk/gtkmm/radioaction.h	Thu Dec 11 01:51:37 2003
@@ -97,7 +97,6 @@
   static Glib::RefPtr<RadioAction> create(Group& group, const Glib::ustring& name, const Glib::ustring& label =  Glib::ustring(), const Glib::ustring& tooltip = Glib::ustring());
   static Glib::RefPtr<RadioAction> create(Group& group, const Glib::ustring& name, const Gtk::StockID& stock_id, const Glib::ustring& label = Glib::ustring(), const Glib::ustring& tooltip =  Glib::ustring());
 
-  typedef RadioButtonGroup Group;
   
   Group get_group();
    void set_group(Group& group);
