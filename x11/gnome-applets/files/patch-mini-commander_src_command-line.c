--- mini-commander/src/command_line.c.orig	2009-02-17 01:16:51.000000000 +0100
+++ mini-commander/src/command_line.c	2009-02-27 21:19:19.000000000 +0100
@@ -312,7 +312,7 @@ mc_show_history (GtkWidget *widget,
      window = gtk_window_new(GTK_WINDOW_POPUP); 
      gtk_window_set_screen (GTK_WINDOW (window),
 			    gtk_widget_get_screen (GTK_WIDGET (mc->applet)));
-     gtk_window_set_resizeable(GTK_WINDOW(window), FALSE);
+     gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
      gtk_window_set_type_hint(GTK_WINDOW(window), GDK_WINDOW_TYPE_HINT_COMBO);
      /* cb */
      g_signal_connect_after(GTK_OBJECT(window),
@@ -507,7 +507,7 @@ mc_show_file_browser (GtkWidget *widget,
 void
 mc_create_command_entry (MCData *mc)
 {
-    mc->entry = gtk_entry_new_with_max ();
+    mc->entry = gtk_entry_new ();
     gtk_entry_set_max_length (GTK_ENTRY (mc->entry), MC_MAX_COMMAND_LENGTH); 
 
     g_signal_connect (mc->entry, "key_press_event",
