--- src/main.c.orig	Mon May 24 20:21:51 2004
+++ src/main.c	Mon May 24 20:23:18 2004
@@ -689,11 +689,7 @@
 int 
 main(int argc, char *argv[])
 {
-#if defined (HAVE_DECL_WNOHANG) || defined (HAVE_DECL_SA_NOCLDWAIT)
-	struct sigaction reapchildren;
-	memset(&reapchildren, 0, sizeof reapchildren);
-#endif /*  WNOHANG/SA_NOCLDWAIT */
-
+	GnomeClient *client;
 	static char *geometry_string = NULL;
 	static const struct poptOption geo_options[] =
 	{
@@ -704,6 +700,11 @@
 		{NULL, '\0', 0, NULL, 0}
 	};
 
+#if defined (HAVE_DECL_WNOHANG) || defined (HAVE_DECL_SA_NOCLDWAIT)
+	struct sigaction reapchildren;
+	memset(&reapchildren, 0, sizeof reapchildren);
+#endif /*  WNOHANG/SA_NOCLDWAIT */
+
 	gnome_program_init(PACKAGE, VERSION, LIBGNOMEUI_MODULE, argc, argv, 
 		                   GNOME_PARAM_POPT_TABLE, geo_options, 
 		                   GNOME_PROGRAM_STANDARD_PROPERTIES, NULL);
@@ -713,7 +714,7 @@
 	bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
 	textdomain(GETTEXT_PACKAGE);
 
-	GnomeClient *client = gnome_master_client();
+	client = gnome_master_client();
 	g_signal_connect(G_OBJECT(client), "save_yourself",
 			   G_CALLBACK(save_state), (gpointer) argv[0]);
 	g_signal_connect(G_OBJECT(client), "die",
