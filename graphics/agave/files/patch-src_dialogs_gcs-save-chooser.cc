--- src/dialogs/gcs-save-chooser.cc.orig	2009-09-27 01:26:32.000000000 +0200
+++ src/dialogs/gcs-save-chooser.cc	2009-09-27 12:00:37.000000000 +0200
@@ -40,7 +40,8 @@ namespace gcs
             m_cancelButton = add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
             m_okButton = add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
             set_do_overwrite_confirmation();
-            m_okButton->can_default();
+            if (m_okButton->get_can_default())
+                        m_okButton->set_can_default();
 
             // update the last saved location in gconf whenever the user
             // presses the "OK" button on the SaveChooser dialog
