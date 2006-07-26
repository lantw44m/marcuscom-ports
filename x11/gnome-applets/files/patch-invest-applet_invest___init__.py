--- invest-applet/invest/__init__.py.orig	Wed Jul 26 17:39:53 2006
+++ invest-applet/invest/__init__.py	Wed Jul 26 17:40:21 2006
@@ -22,7 +22,7 @@ if UNINSTALLED_INVEST:
 	SHARED_DATA_DIR = abspath(join(dirname(__file__), '..', 'data'))
 	GLADE_DATA_DIR = SHARED_DATA_DIR
 else:
-	SHARED_DATA_DIR = join(DATA_DIR, "gnome-applets", "invest-applet")
+	SHARED_DATA_DIR = join(DATA_DIR, "gnome-applets")
 	GLADE_DATA_DIR = join(SHARED_DATA_DIR, "glade")
 print "Data Dir: %s" % SHARED_DATA_DIR
 
