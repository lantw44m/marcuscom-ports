--- deskbar/handlers/mozilla.py.orig	2007-08-06 07:17:47.000000000 -0400
+++ deskbar/handlers/mozilla.py	2007-08-06 13:02:46.000000000 -0400
@@ -211,6 +211,7 @@ class MozillaSearchHandler(deskbar.inter
 			smart_dirs = [
 				get_mozilla_home_file("search"),
 				expanduser("~/.mozilla/searchplugins"),
+				"%%LOCALBASE%%/lib/mozilla/searchplugins",
 				"/usr/lib/mozilla/searchplugins",
 				"/usr/local/lib/mozilla/searchplugins"]
 		
