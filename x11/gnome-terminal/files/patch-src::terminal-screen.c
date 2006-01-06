--- src/terminal-screen.c.orig	Thu Jan  5 16:04:24 2006
+++ src/terminal-screen.c	Fri Jan  6 12:34:25 2006
@@ -282,25 +282,20 @@ terminal_screen_init (TerminalScreen *sc
 #define URLPATH   "/[" PATHCHARS "]*[^]'.}>) \t\r\n,\\\"]"
 
   terminal_widget_match_add (screen->priv->term,
-			     "\\<(" SCHEME "://(" USER "@)?)[" HOSTCHARS ".]+"
-			     "(:[0-9]+)?(" URLPATH ")?", FLAVOR_AS_IS);
+		  "[[:<:]](" SCHEME "://(" USER "@)?)[" HOSTCHARS ".]+(:[0-9]+)?(" URLPATH ")?", FLAVOR_AS_IS);
 
   terminal_widget_match_add (screen->priv->term,
-			     "\\<(www|ftp)[" HOSTCHARS "]*\\.[" HOSTCHARS ".]+"
-			     "(:[0-9]+)?(" URLPATH ")?",
-			     FLAVOR_DEFAULT_TO_HTTP);
+		  "[[:<:]]<(www|ftp)[" HOSTCHARS "]*\\.[" HOSTCHARS ".]+(:[0-9]+)?(" URLPATH ")?", FLAVOR_DEFAULT_TO_HTTP);
 
   terminal_widget_match_add (screen->priv->term,
-			     "\\<mailto:[a-z0-9][a-z0-9.-]*@[a-z0-9][a-z0-9-]*"
-			     "(\\.[a-z0-9][a-z0-9-]*)+\\>", FLAVOR_MAILTO);
+		  "[[:<:]](mailto:)?[a-z0-9][a-z0-9.-]*@[a-z0-9][a-z0-9-]*(\\.[a-z0-9][a-z0-9-]*)+\\>", FLAVOR_MAILTO);
 
   terminal_widget_match_add (screen->priv->term,
-			     "\\<[a-z0-9][a-z0-9.-]*@[a-z0-9][a-z0-9-]*"
+			     "[[:<:]][a-z0-9][a-z0-9.-]*@[a-z0-9][a-z0-9-]*"
 			     "(\\.[a-z0-9][a-z0-9-]*)+\\>", FLAVOR_EMAIL);
 
   terminal_widget_match_add (screen->priv->term,
-			     "\\<news:[-A-Z\\^_a-z{|}~!\"#$%&'()*+,./0-9;:=?`]+"
-			     "@[" HOSTCHARS ".]+(:[0-9]+)?\\>", FLAVOR_AS_IS);
+		  "[[:<:]]<news:[-A-Z\\^_a-z{|}~!\"#$%&'()*+,./0-9;:=?`]+@[" HOSTCHARS ".]+(:[0-9]+)?\\>", FLAVOR_AS_IS);
 
   terminal_screen_setup_dnd (screen);
 
