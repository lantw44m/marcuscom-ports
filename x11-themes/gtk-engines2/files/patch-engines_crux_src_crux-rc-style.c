--- engines/crux/src/crux-rc-style.c.orig	Thu Dec 23 16:14:48 2004
+++ engines/crux/src/crux-rc-style.c	Thu Dec 23 16:15:02 2004
@@ -20,9 +20,10 @@
 static void
 crux_rc_style_init (CruxRcStyle *style)
 {
+  gchar *path;
   style->theme_data = NULL;
   
-  gchar *path = g_malloc (strlen (DATADIR) + 15);
+  path = g_malloc (strlen (DATADIR) + 15);
   sprintf (path, "pixmap_path \"%s\"", DATADIR);
 
   gtk_rc_parse_string (path);
