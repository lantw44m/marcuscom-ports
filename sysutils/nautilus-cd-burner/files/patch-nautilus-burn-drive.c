--- nautilus-burn-drive.c.orig	Tue Aug 23 11:55:56 2005
+++ nautilus-burn-drive.c	Mon Sep  5 15:04:22 2005
@@ -471,7 +471,6 @@ get_disc_type (const char *dev_path)
 	struct cd_toc_entry              entry;
 	int                              i;
 #endif
-	int                              type;
 #ifndef CDROM_DATA_TRACK
 #define CDROM_DATA_TRACK 4
 #endif
