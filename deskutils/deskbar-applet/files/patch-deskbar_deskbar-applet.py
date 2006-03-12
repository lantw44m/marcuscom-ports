--- deskbar/deskbar-applet.py.orig	Sat Mar 11 18:05:44 2006
+++ deskbar/deskbar-applet.py	Sun Mar 12 17:19:57 2006
@@ -41,9 +41,9 @@ gettext.bindtextdomain('deskbar-applet',
 gettext.bind_textdomain_codeset('deskbar-applet','UTF-8')
 gettext.textdomain('deskbar-applet')
 
-locale.bindtextdomain('deskbar-applet', abspath(join(deskbar.defs.DATA_DIR, "locale")))
-locale.bind_textdomain_codeset('deskbar-applet','UTF-8')
-locale.textdomain('deskbar-applet')
+#locale.bindtextdomain('deskbar-applet', abspath(join(deskbar.defs.DATA_DIR, "locale")))
+#locale.bind_textdomain_codeset('deskbar-applet','UTF-8')
+#locale.textdomain('deskbar-applet')
 
 import gtkexcepthook
 
