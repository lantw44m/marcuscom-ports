--- nautilus-burn-drive.c.orig	Wed Jan 26 17:42:58 2005
+++ nautilus-burn-drive.c	Thu Feb 10 16:59:01 2005
@@ -62,6 +62,13 @@
 
 #define CD_ROM_SPEED 176
 
+#if !defined(__linux)
+static int get_device_max_read_speed (char *device);
+#endif
+#if defined(__linux__) || defined(__FreeBSD__)
+static int get_device_max_write_speed (char *device);
+#endif
+
 static struct {
 	const char *name;
 	gboolean can_write_cdr;
@@ -149,7 +156,7 @@
 		   int                   *max_wr_speed,
 		   NautilusBurnDriveType *type)
 {
-	char *stdout_data, *rd_speed, *wr_speed, *drive_cap;
+	char *stdout_data, *drive_cap;
 
 	*max_rd_speed = -1;
 	*max_wr_speed = -1;
@@ -278,6 +285,9 @@
 {
 	int fd;
 	int mmc_profile;
+#ifdef __FreeBSD__
+	struct cam_device *cam;
+#endif
 
 	g_return_val_if_fail (device != NULL, NAUTILUS_BURN_MEDIA_TYPE_ERROR);
 
@@ -286,6 +296,15 @@
 	if (has_data) *has_data = FALSE;
 	if (has_audio) *has_audio = FALSE;
 
+#ifdef __FreeBSD__
+	cam = cam_open_device (device, O_RDWR);
+	if (cam == NULL) {
+		return NAUTILUS_BURN_MEDIA_TYPE_ERROR;
+	}
+
+	fd = cam->fd;
+#else
+
 	fd = open (device, O_RDWR|O_EXCL|O_NONBLOCK);
 	if (fd < 0) {
 		if (errno == EBUSY) {
@@ -293,6 +312,7 @@
 		}
 		return NAUTILUS_BURN_MEDIA_TYPE_ERROR;
 	}
+#endif
 
 	mmc_profile = get_mmc_profile (fd);
 
@@ -333,7 +353,11 @@
 		}
 	}
 
+#ifdef __FreeBSD__
+	cam_close_device (cam);
+#else
 	close (fd);
+#endif
 
 	switch (mmc_profile) {
 	case -1:
@@ -563,10 +587,21 @@
 	int    secs;
 	int    mmc_profile;
 	gint64 size;
+#ifdef __FreeBSD__
+	struct cam_device *cam;
+#endif
 
 	g_return_val_if_fail (device != NULL, NAUTILUS_BURN_MEDIA_SIZE_UNKNOWN);
 
 	secs = 0;
+#ifdef __FreeBSD__
+	cam = cam_open_device (device, O_RDWR);
+	if (cam == NULL) {
+		return NAUTILUS_BURN_MEDIA_SIZE_UNKNOWN;
+	}
+
+	fd = cam->fd;
+#else
 
 	fd = open (device, O_RDWR|O_EXCL|O_NONBLOCK);
 	if (fd < 0) {
@@ -575,6 +610,7 @@
 		}
 		return NAUTILUS_BURN_MEDIA_SIZE_UNKNOWN;
 	}
+#endif
 
 	mmc_profile = get_mmc_profile (fd);
 
@@ -597,7 +633,11 @@
 		size = NAUTILUS_BURN_MEDIA_SIZE_NA;
 	}
 
+#ifdef __FreeBSD__
+	cam_close_device (cam);
+#else
 	close (fd);
+#endif
 
 	return size;
 }
@@ -890,9 +930,81 @@
 #endif /* USE_HAL */
 
 #if defined(__linux__) || defined(__FreeBSD__)
+static int
+get_device_max_write_speed (char *device)
+{
+	int fd;
+	int max_speed;
+	int read_speed, write_speed;
+#ifdef __FreeBSD__
+	struct cam_device *cam;
+#endif
+
+	max_speed = -1;
+#ifdef __FreeBSD__
+	cam = cam_open_device (device, O_RDWR);
+	if (cam == NULL) {
+		return -1;
+	}
+
+	fd = cam->fd;
+#else
+
+	fd = open (device, O_RDWR|O_EXCL|O_NONBLOCK);
+	if (fd < 0) {
+		return -1;
+	}
+#endif
+
+	get_read_write_speed (fd, &read_speed, &write_speed);
+#ifdef __FreeBSD__
+	cam_close_device (cam);
+#else
+	close (fd);
+#endif
+	max_speed = (int)floor  (write_speed) / CD_ROM_SPEED;
+
+	return max_speed;
+}
+
+#if !defined(__linux)
+static int
+get_device_max_read_speed (char *device)
+{
+	int fd;
+	int max_speed;
+	int read_speed, write_speed;
+#ifdef __FreeBSD__
+	struct cam_device *cam;
+#endif
+
+	max_speed = -1;
+#ifdef __FreeBSD__
+	cam = cam_open_device (device, O_RDWR);
+	if (cam == NULL) {
+		return -1;
+	}
 
+	fd = cam->fd;
+#else
 
+	fd = open (device, O_RDWR|O_EXCL|O_NONBLOCK);
+	if (fd < 0) {
+		return -1;
+	}
+#endif
+
+	get_read_write_speed (fd, &read_speed, &write_speed);
+#ifdef __FreeBSD__
+	cam_close_device (cam);
+#else
+	close (fd);
+#endif
+	max_speed = (int)floor  (read_speed) / CD_ROM_SPEED;
 
+	return max_speed;
+}
+#endif
 #endif /* __linux__ || __FreeBSD__ */
 
 #if defined (__linux__)
@@ -1104,49 +1216,7 @@
 	return NULL;
 }
 
-#if !defined(__linux)
-static int
-get_device_max_read_speed (char *device)
-{
-	int fd;
-	int max_speed;
-	int read_speed, write_speed;
-
-	max_speed = -1;
-
-	fd = open (device, O_RDWR|O_EXCL|O_NONBLOCK);
-	if (fd < 0) {
-		return -1;
-	}
-
-	get_read_write_speed (fd, &read_speed, &write_speed);
-	close (fd);
-	max_speed = (int)floor  (read_speed) / CD_ROM_SPEED;
-
-	return max_speed;
-}
-#endif
-
-static int
-get_device_max_write_speed (char *device)
-{
-	int fd;
-	int max_speed;
-	int read_speed, write_speed;
-
-	max_speed = -1;
 
-	fd = open (device, O_RDWR|O_EXCL|O_NONBLOCK);
-	if (fd < 0) {
-		return -1;
-	}
-
-	get_read_write_speed (fd, &read_speed, &write_speed);
-	close (fd);
-	max_speed = (int)floor  (write_speed) / CD_ROM_SPEED;
-
-	return max_speed;
-}
 
 static char *
 get_scsi_cd_name (int               bus,
