--- stickynotes/stickynotes_applet_callbacks.c.orig	Sat Apr 12 17:17:50 2003
+++ stickynotes/stickynotes_applet_callbacks.c	Sat Apr 12 17:19:37 2003
@@ -168,19 +168,26 @@
 /* Menu Callback : Configure preferences */
 void menu_preferences_cb(BonoboUIComponent *uic, StickyNotesApplet *stickynotes, const gchar *verbname)
 {
+    	GtkWidget *preferences_dialog;
+	GtkAdjustment *width_adjust;
+	GtkAdjustment *height_adjust;
+	GtkWidget *sticky_check;
+	GtkWidget *note_color;
+	GtkWidget *click_behavior_menu;
+
 	if (stickynotes->prefs != NULL) {
 		gdk_window_raise(glade_xml_get_widget(stickynotes->prefs, "preferences_dialog")->window);
 		return;
 	}
 	
 	stickynotes->prefs = glade_xml_new(GLADE_PATH, "preferences_dialog", NULL);
-	GtkWidget *preferences_dialog = glade_xml_get_widget(stickynotes->prefs, "preferences_dialog");
+	preferences_dialog = glade_xml_get_widget(stickynotes->prefs, "preferences_dialog");
 	
-	GtkAdjustment *width_adjust = gtk_spin_button_get_adjustment(GTK_SPIN_BUTTON(glade_xml_get_widget(stickynotes->prefs, "width_spin")));
-	GtkAdjustment *height_adjust = gtk_spin_button_get_adjustment(GTK_SPIN_BUTTON(glade_xml_get_widget(stickynotes->prefs, "height_spin")));
-	GtkWidget *sticky_check = glade_xml_get_widget(stickynotes->prefs, "sticky_check");
-	GtkWidget *note_color = glade_xml_get_widget(stickynotes->prefs, "note_color");
-	GtkWidget *click_behavior_menu = glade_xml_get_widget(stickynotes->prefs, "click_behavior_menu");
+	width_adjust = gtk_spin_button_get_adjustment(GTK_SPIN_BUTTON(glade_xml_get_widget(stickynotes->prefs, "width_spin")));
+	height_adjust = gtk_spin_button_get_adjustment(GTK_SPIN_BUTTON(glade_xml_get_widget(stickynotes->prefs, "height_spin")));
+	sticky_check = glade_xml_get_widget(stickynotes->prefs, "sticky_check");
+	note_color = glade_xml_get_widget(stickynotes->prefs, "note_color");
+	click_behavior_menu = glade_xml_get_widget(stickynotes->prefs, "click_behavior_menu");
 
 	{
 		GtkSizeGroup *size= gtk_size_group_new(GTK_SIZE_GROUP_HORIZONTAL);
@@ -232,13 +239,15 @@
 /* Menu Callback : Display About window */
 void menu_about_cb(BonoboUIComponent *uic, StickyNotesApplet *stickynotes, const gchar *verbname)
 {
+    	GtkWidget *about_dialog;
+
 	if (stickynotes->about != NULL) {
 		gdk_window_raise(glade_xml_get_widget(stickynotes->about, "about_dialog")->window);
 		return;
 	}
 	
 	stickynotes->about = glade_xml_new(GLADE_PATH, "about_dialog", NULL);
-	GtkWidget *about_dialog = glade_xml_get_widget(stickynotes->about, "about_dialog");
+	about_dialog = glade_xml_get_widget(stickynotes->about, "about_dialog");
 
 	g_signal_connect(G_OBJECT(about_dialog), "response", G_CALLBACK(about_response_cb), stickynotes);
 
