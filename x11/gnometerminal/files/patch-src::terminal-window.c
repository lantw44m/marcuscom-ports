--- src/terminal-window.c.orig	Wed Nov  5 01:50:14 2003
+++ src/terminal-window.c	Tue Jan 27 22:57:22 2004
@@ -778,6 +778,11 @@
       menus_have_icons = TRUE;
     }
  
+  g_signal_connect (window->priv->menubar,
+		    "can_activate_accel",
+		    G_CALLBACK (gtk_true),
+		    NULL);
+  
   accel_group = terminal_accels_get_group_for_widget (GTK_WIDGET (window));
   gtk_window_add_accel_group (GTK_WINDOW (window), accel_group);
   
