--- src/extension/db.cpp.orig	Sat Jul 17 11:50:33 2004
+++ src/extension/db.cpp	Sat Jul 17 11:52:55 2004
@@ -80,7 +80,13 @@
 
 	if (key == NULL) return NULL;
 
-	mod = (*moduledict.find(key)).second;
+	std::map <const char *, Extension *, ltstr>::const_iterator i =
+		moduledict.find(key);
+
+	if (i == moduledict.end())
+		return NULL;
+
+	mod = i->second;
 
 	if ( !mod || mod->deactivated() )
 		return NULL;
