--- sysdeps/common/mountlist.c.orig	Sun Feb 19 22:34:38 2006
+++ sysdeps/common/mountlist.c	Sun Feb 19 22:37:33 2006
@@ -540,7 +540,9 @@ static gboolean ignore_mount_entry(const
 	static const char ignored[][12] = {
 		"autofs",
 		"binfmt_misc",
+		"devfs",
 		"devpts",
+		"linprocfs",
 		"mntfs",
 		"mqueue",
 		"none",
