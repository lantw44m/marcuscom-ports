--- hamster/hamster-applet.py.orig	2009-12-18 20:42:05.000000000 +0100
+++ hamster/hamster-applet.py	2009-12-25 16:38:19.000000000 +0100
@@ -102,13 +102,13 @@ if __name__ == "__main__":
         from hamster.configuration import runtime
         
         # Setup i18n
-        locale_dir = os.path.abspath(os.path.join(defs.DATA_DIR, "locale"))        
-        for module in (gettext, locale):
-            module.bindtextdomain('hamster-applet', locale_dir)
-            module.textdomain('hamster-applet')
+#        locale_dir = os.path.abspath(os.path.join(defs.DATA_DIR, "locale"))        
+#        for module in (gettext, locale):
+#            module.bindtextdomain('hamster-applet', locale_dir)
+#            module.textdomain('hamster-applet')
         
-            if hasattr(module, 'bind_textdomain_codeset'):
-                module.bind_textdomain_codeset('hamster-applet','UTF-8')
+#            if hasattr(module, 'bind_textdomain_codeset'):
+#                module.bind_textdomain_codeset('hamster-applet','UTF-8')
         
         gtk.window_set_default_icon_name("hamster-applet")
     
