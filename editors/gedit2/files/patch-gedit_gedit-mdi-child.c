--- gedit/gedit-mdi-child.c.orig	Wed Jan 14 17:16:40 2004
+++ gedit/gedit-mdi-child.c	Wed Jan 14 17:18:00 2004
@@ -37,7 +37,7 @@
 #include <libgnomevfs/gnome-vfs.h>
 #include <libgnomevfs/gnome-vfs-mime-utils.h>
 #include <libgnomevfs/gnome-vfs-mime-handlers.h>
-#include <eel/eel-input-event-box.h>
+#include <gtk/gtkeventbox.h>
 
 #include <bonobo/bonobo-i18n.h>
 
@@ -751,7 +751,8 @@
 						   &w, &h);
 
 		/* create our layout/event boxes */
-		event_box = eel_input_event_box_new();
+		event_box = gtk_event_box_new();
+		gtk_event_box_set_visible_window (GTK_EVENT_BOX (event_box), FALSE);
 		event_hbox = gtk_hbox_new (FALSE, 0);
 		hbox = gtk_hbox_new (FALSE, 0);
 
