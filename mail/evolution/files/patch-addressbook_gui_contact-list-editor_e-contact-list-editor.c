--- addressbook/gui/contact-list-editor/e-contact-list-editor.c.orig	Mon Jul  5 18:18:22 2004
+++ addressbook/gui/contact-list-editor/e-contact-list-editor.c	Mon Jul  5 18:18:59 2004
@@ -666,11 +666,15 @@
 
 	EContactListEditor *ce;
 
+	Bonobo_Control corba_control;
+
+	GtkWidget *control_widget;
+
 	ce = E_CONTACT_LIST_EDITOR (data);
 
-	Bonobo_Control corba_control = GNOME_Evolution_Addressbook_SelectNames_getEntryBySection
+	corba_control = GNOME_Evolution_Addressbook_SelectNames_getEntryBySection
 			(ce->corba_select_names, "Members", ev);
-	GtkWidget *control_widget = bonobo_widget_new_control_from_objref (corba_control, CORBA_OBJECT_NIL);
+	control_widget = bonobo_widget_new_control_from_objref (corba_control, CORBA_OBJECT_NIL);
 
 	bonobo_widget_get_property (BONOBO_WIDGET (control_widget), "destinations",
 					    TC_CORBA_string, &string, NULL);
