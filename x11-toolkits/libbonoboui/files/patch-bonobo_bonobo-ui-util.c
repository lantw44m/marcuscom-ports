--- bonobo/bonobo-ui-util.c.orig	Fri May 14 06:49:07 2004
+++ bonobo/bonobo-ui-util.c	Wed Jan 26 13:24:13 2005
@@ -400,7 +400,8 @@
 			g_warning ("Could not find GNOME pixmap file %s", text);
 		else {
  			int w, h;
- 			if (gtk_icon_size_lookup (icon_size, &w, &h))
+			GtkSettings *settings = gtk_widget_get_settings (GTK_WIDGET (image));
+			if (gtk_icon_size_lookup_for_settings (settings, icon_size, &w, &h))
  				pixbuf = gdk_pixbuf_new_from_file_at_size (name, w, h, NULL);
  			else
  				pixbuf = gdk_pixbuf_new_from_file (name, NULL);
@@ -564,14 +565,11 @@
 		else
 			prefix = NULL;
 
-		if (prefix)
+		datadir = NULL;
+		g_object_get (G_OBJECT (gnome_program_get ()),
+			GNOME_PARAM_APP_DATADIR, &datadir, NULL);
+		if (!datadir && prefix) 
 			datadir = g_strdup_printf ("%s/share", prefix);
-
- 		else {
-			datadir = NULL;
-			g_object_get (G_OBJECT (gnome_program_get ()),
-				      GNOME_PARAM_APP_DATADIR, &datadir, NULL);
-		}
 
 		if (!datadir) /* desparate fallback */
 			datadir = g_strdup (BONOBO_DATADIR);
