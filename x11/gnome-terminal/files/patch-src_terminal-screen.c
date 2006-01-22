===================================================================
RCS file: /cvs/gnome/gnome-terminal/src/terminal-screen.c,v
retrieving revision 1.118
retrieving revision 1.119
diff -u -r1.118 -r1.119
--- src/terminal-screen.c	2006/01/16 19:25:25	1.118
+++ src/terminal-screen.c	2006/01/20 18:05:37	1.119
@@ -45,9 +45,6 @@
 #define MONOSPACE_FONT_DIR "/desktop/gnome/interface"
 #define MONOSPACE_FONT_KEY MONOSPACE_FONT_DIR "/monospace_font_name"
 #define HTTP_PROXY_DIR "/system/http_proxy"
-#define HTTP_PROXY_HOST HTTP_PROXY_DIR "/host"
-#define HTTP_PROXY_PORT HTTP_PROXY_DIR "/port"
-#define HTTP_PROXY_USE_PROXY HTTP_PROXY_DIR "/use_http_proxy"
 
 struct _TerminalScreenPrivate
 {
@@ -56,7 +53,6 @@
   TerminalProfile *profile; /* may be NULL at times */
   guint profile_changed_id;
   guint profile_forgotten_id;
-  int id;
   GtkWidget *popup_menu;
   char *raw_title, *raw_icon_title;
   char *cooked_title, *cooked_icon_title;
@@ -76,8 +72,6 @@
   gboolean user_title; /* title was manually set */
 };
 
-static GList* used_ids = NULL;
-
 enum {
   PROFILE_SET,
   TITLE_CHANGED,
@@ -289,7 +283,7 @@
 			     "(:[0-9]+)?(" URLPATH ")?\\>", FLAVOR_AS_IS);
 
   terminal_widget_match_add (screen->priv->term,
-			     "\\<(file:///(" URLPATH ")?", FLAVOR_AS_IS);
+			     "\\<file:///(" URLPATH ")?", FLAVOR_AS_IS);
 			     
 
   terminal_widget_match_add (screen->priv->term,
@@ -450,8 +444,6 @@
 
   g_object_unref (conf);
 
-  used_ids = g_list_remove (used_ids, GINT_TO_POINTER (screen->priv->id));  
-
   if (screen->priv->title_editor)
     gtk_widget_destroy (screen->priv->title_editor);
   
@@ -473,30 +465,10 @@
   G_OBJECT_CLASS (parent_class)->finalize (object);
 }
 
-static int
-next_unused_id (void)
-{
-  /* can't this be changed into a static unsigned long int? These ids are never used anyways...*/
-  int i = 0;
-
-  while (g_list_find (used_ids, GINT_TO_POINTER (i)))
-    ++i;
-
-  return i;
-}
-
 TerminalScreen*
 terminal_screen_new (void)
 {
-  TerminalScreen *screen;
-
-  screen = g_object_new (TERMINAL_TYPE_SCREEN, NULL);
-  
-  screen->priv->id = next_unused_id ();
-
-  used_ids = g_list_prepend (used_ids, GINT_TO_POINTER (screen->priv->id));
-  
-  return screen;
+  return g_object_new (TERMINAL_TYPE_SCREEN, NULL);
 }
 
 static void
@@ -512,12 +484,6 @@
   GTK_WIDGET_CLASS (parent_class)->map (widget);
 }
 
-int
-terminal_screen_get_id (TerminalScreen *screen)
-{
-  return screen->priv->id;
-}
-
 TerminalWindow*
 terminal_screen_get_window (TerminalScreen *screen)
 {
@@ -655,7 +621,6 @@
   
   terminal_widget_set_delete_binding (term,
                                       terminal_profile_get_delete_binding (profile));
-
 }
 
 /**
@@ -835,7 +800,7 @@
                                        pango_font_description_get_size (desc));
 
       terminal_widget_set_pango_font (term, desc,
-      					terminal_profile_get_no_aa_without_render(profile));
+				      terminal_profile_get_no_aa_without_render (profile));
 
       pango_font_description_free (desc);
     }
@@ -1118,19 +1083,16 @@
 get_child_environment (GtkWidget      *term,
                        TerminalScreen *screen)
 {
-  /* code from gnome-terminal, sort of. */
-  TerminalProfile *profile;
-  char **p;
-  int i;
-  char **retval;
+  gchar **p, **retval;
+  gint i;
+  GConfClient *conf;
+  gboolean use_proxy;
 #define EXTRA_ENV_VARS 8
-  
-  profile = screen->priv->profile;
 
   /* count env vars that are set */
   for (p = environ; *p; p++)
     ;
-  
+
   i = p - environ;
   retval = g_new (char *, i + 1 + EXTRA_ENV_VARS);
 
@@ -1143,7 +1105,7 @@
           (strncmp (*p, "TERM=", 5) == 0)    ||
           (strncmp (*p, "GNOME_DESKTOP_ICON=", 19) == 0) ||
           (strncmp (*p, "COLORTERM=", 10) == 0) ||
-	  (strncmp ( *p, "DISPLAY=", 8) == 0))
+	  (strncmp (*p, "DISPLAY=", 8) == 0))
         {
           /* nothing: do not copy */
         }
@@ -1156,35 +1118,85 @@
 
   retval[i] = g_strdup ("COLORTERM="EXECUTABLE_NAME);
   ++i;
+
   retval[i] = g_strdup ("TERM=xterm"); /* FIXME configurable later? */
   ++i;
+
   retval[i] = g_strdup_printf ("WINDOWID=%ld",
                                GDK_WINDOW_XWINDOW (term->window));
   ++i;
+
   retval[i] = g_strdup_printf ("DISPLAY=%s", 
 			       gdk_display_get_name(gtk_widget_get_display(term)));
   ++i;
   
-  /* Setup HTTP proxy according to gconf */
-  GConfClient *conf = gconf_client_get_default ();
-  gchar *host = gconf_client_get_string (
-    conf, HTTP_PROXY_HOST, NULL);
-  gint port = gconf_client_get_int (
-    conf, HTTP_PROXY_PORT, NULL);
-  gboolean use_proxy = gconf_client_get_bool (
-    conf, HTTP_PROXY_USE_PROXY, NULL);
+  conf = gconf_client_get_default ();
+  use_proxy = gconf_client_get_bool (conf, HTTP_PROXY_DIR "/use_http_proxy", NULL);
+
+  if (use_proxy && !getenv ("http_proxy"))
+    {
+      gchar *host;
+      gint port;
+      GSList *ignore;
+
+      host = gconf_client_get_string (conf, HTTP_PROXY_DIR "/host", NULL);
+      port = gconf_client_get_int (conf, HTTP_PROXY_DIR "/port", NULL);
+      ignore = gconf_client_get_list (conf, HTTP_PROXY_DIR "/ignore_hosts",
+				      GCONF_VALUE_STRING, NULL);
+
+      g_object_unref (conf);
+
+      if (host && port)
+	{
+	  retval[i] = g_strdup_printf ("http_proxy=http://%s:%d/", host, port);
+	  g_free (host);
+	  ++i;
+	}
+
+      if (ignore)
+	{
+	  /* code distantly based on gconf's */
+	  gchar *buf = NULL;
+	  guint bufsize = 64;
+	  guint cur = 0;
+
+	  buf = g_malloc (bufsize + 3);
+
+	  while (ignore != NULL)
+	    {
+	      guint len = strlen (ignore->data);
+
+	      if ((cur + len + 2) >= bufsize) /* +2 for '\0' and comma */
+		{
+		  bufsize = MAX(bufsize * 2, bufsize + len + 4); 
+		  buf = g_realloc (buf, bufsize + 3);
+		}
+
+	      g_assert (cur < bufsize);
+
+	      strcpy (&buf[cur], ignore->data);
+	      cur += len;
+
+	      g_assert(cur < bufsize);
+
+	      buf[cur] = ',';
+	      ++cur;
+
+	      g_assert(cur < bufsize);
+
+	      ignore = g_slist_next (ignore);
+	    }
+
+	  buf[cur-1] = '\0'; /* overwrites last comma */
+
+	  retval[i] = g_strdup_printf ("no_proxy=%s", buf);
+	  g_free (buf);
+	  ++i;
+	}
+    }
 
-  if (host && port && !getenv ("http_proxy") && use_proxy)
-    retval[i] = g_strdup_printf ("http_proxy=%s:%d", host, port);
-  else
-    retval[i] = g_strdup_printf ("");
-  
-  if (host)
-    g_free (host);
-  ++i;
-  
   retval[i] = NULL;
-  
+
   return retval;
 }
 
