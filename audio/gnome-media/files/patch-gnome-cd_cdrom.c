--- gnome-cd/cdrom.c.orig	Sat Mar 12 01:00:51 2005
+++ gnome-cd/cdrom.c	Sat Mar 12 01:02:57 2005
@@ -358,9 +358,14 @@ cdrom_open_dev (GnomeCDRom *cdrom,
 {
 	if (cdrom->priv->open_count++ == 0) {
 		cdrom->fd = open (
+#if defined(__FreeBSD__)
+			cdrom->priv->device, O_RDONLY);
+#else
 			cdrom->priv->device, O_RDONLY | O_NONBLOCK);
+#endif
 
 		if (cdrom->fd < 0) {
+			g_warning ("XXX: Failed to open %s: %s", cdrom->priv->device, strerror(errno));
 			if (errno == EACCES && error != NULL) {
 				*error = g_error_new (
 					GNOME_CDROM_ERROR,
