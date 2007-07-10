--- deskbar/core/Utils.py.orig	Tue Jul 10 15:24:06 2007
+++ deskbar/core/Utils.py	Tue Jul 10 15:24:23 2007
@@ -51,7 +51,7 @@
 	
 	sysdirs = os.getenv("XDG_DATA_DIRS")
 	if sysdirs == None:
-		sysdirs = "/usr/local/share:/usr/share"
+		sysdirs = "/usr/local/share"
 	
 	dirs = "%s:%s" % (dirs, sysdirs)
 	return [dir for dir in dirs.split(":") if dir.strip() != "" and exists(dir)]
