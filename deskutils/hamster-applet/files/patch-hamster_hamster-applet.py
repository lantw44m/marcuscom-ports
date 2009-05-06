--- hamster/hamster-applet.py.orig	2009-04-25 14:29:45.000000000 +0200
+++ hamster/hamster-applet.py	2009-05-06 17:47:09.000000000 +0200
@@ -40,14 +40,14 @@ if _check(name):
 import hamster.defs
 
 # Setup i18n
-locale_dir = os.path.abspath(os.path.join(hamster.defs.DATA_DIR, "locale"))
+#locale_dir = os.path.abspath(os.path.join(hamster.defs.DATA_DIR, "locale"))
 
-for module in (gettext, locale):
-    module.bindtextdomain('hamster-applet', locale_dir)
-    module.textdomain('hamster-applet')
+#for module in (gettext, locale):
+#    module.bindtextdomain('hamster-applet', locale_dir)
+#    module.textdomain('hamster-applet')
 
-    if hasattr(module, 'bind_textdomain_codeset'):
-        module.bind_textdomain_codeset('hamster-applet','UTF-8')
+#    if hasattr(module, 'bind_textdomain_codeset'):
+#        module.bind_textdomain_codeset('hamster-applet','UTF-8')
 
 
 hamster.__init_db()
