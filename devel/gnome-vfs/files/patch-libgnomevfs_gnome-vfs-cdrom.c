--- libgnomevfs/gnome-vfs-cdrom.c.orig	Mon Dec  8 18:20:28 2003
+++ libgnomevfs/gnome-vfs-cdrom.c	Mon Dec  8 18:12:46 2003
@@ -165,6 +165,8 @@
 	struct iso_primary_descriptor iso_buffer;
 	int offset;
 
+	bzero (&iso_buffer, sizeof(struct iso_primary_descriptor));
+
 #ifdef __linux__
 	offset = get_iso9660_volume_name_data_track_offset (fd);
 #else
