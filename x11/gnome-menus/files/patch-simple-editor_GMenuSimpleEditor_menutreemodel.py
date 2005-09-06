--- simple-editor/GMenuSimpleEditor/menutreemodel.py.orig	Tue Sep  6 10:53:47 2005
+++ simple-editor/GMenuSimpleEditor/menutreemodel.py	Tue Sep  6 10:56:02 2005
@@ -29,7 +29,7 @@
     if os.environ.has_key ("XDG_CONFIG_DIRS"):
         conf_dirs = os.environ["XDG_CONFIG_DIRS"]
     if not conf_dirs:
-        conf_dirs = "/etc/xdg"
+	conf_dirs = "%%X11BASE%%/share/gnome/:/usr/local/share/gnome/:%%X11BASE%%/share/:/usr/local/share/:/usr/share/"
 
     for conf_dir in conf_dirs.split (":"):
         menu_file_path = os.path.join (conf_dir, "menus", menu_file)
