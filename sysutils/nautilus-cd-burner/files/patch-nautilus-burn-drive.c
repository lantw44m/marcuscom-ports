--- nautilus-burn-drive.c.orig	Mon Feb 28 19:51:06 2005
+++ nautilus-burn-drive.c	Mon Feb 28 20:01:09 2005
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
 	if ((fd = open (device, O_RDWR | O_EXCL | O_NONBLOCK)) < 0
 	    && (fd = open (device, O_RDONLY | O_EXCL | O_NONBLOCK)) < 0) {
 		if (errno == EBUSY) {
@@ -293,6 +312,7 @@
 		}
 		return NAUTILUS_BURN_MEDIA_TYPE_ERROR;
 	}
+#endif
 
 	mmc_profile = get_mmc_profile (fd);
 
@@ -330,7 +350,11 @@
 		}
 	}
 
+#ifdef __FreeBSD__
+	cam_close_device (cam);
+#else
 	close (fd);
+#endif
 
 	if (is_blank)
 		*is_blank = mmc_profile & 0x10000;
@@ -569,11 +593,21 @@
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
 
+	fd = cam->fd;
+#else
 	if ((fd = open (device, O_RDWR | O_EXCL | O_NONBLOCK)) < 0
 	    && (fd = open (device, O_RDONLY | O_EXCL | O_NONBLOCK)) < 0) {
 		if (errno == EBUSY) {
@@ -581,6 +615,7 @@
 		}
 		return NAUTILUS_BURN_MEDIA_SIZE_UNKNOWN;
 	}
+#endif
 
 	mmc_profile = get_mmc_profile (fd);
 
@@ -603,7 +638,11 @@
 		size = NAUTILUS_BURN_MEDIA_SIZE_NA;
 	}
 
+#ifdef __FreeBSD__
+	cam_close_device (cam);
+#else
 	close (fd);
+#endif
 
 	return size;
 }
@@ -896,9 +935,81 @@
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
+ 
+	fd = cam->fd;
+#else
+ 
+	fd = open (device, O_RDWR|O_EXCL|O_NONBLOCK);
+	if (fd < 0) {
+		return -1;
+	}
+#endif
 
+	get_read_write_speed (fd, &read_speed, &write_speed);
+#ifdef __FreeBSD__
+	cam_close_device (cam);
+#else
+	close (fd);
+#endif
+	max_speed = (int)floor  (read_speed) / CD_ROM_SPEED;
+ 
+	return max_speed;
+}
+#endif
 #endif /* __linux__ || __FreeBSD__ */
 
 #if defined (__linux__)
@@ -1111,50 +1222,6 @@
 		}
 	}
 	return NULL;
-}
-
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
-	if ((fd = open (device, O_RDWR | O_EXCL | O_NONBLOCK)) < 0
-	    && (fd = open (device, O_RDONLY | O_EXCL | O_NONBLOCK)) < 0) {
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
-
-	if ((fd = open (device, O_RDWR | O_EXCL | O_NONBLOCK)) < 0
-	    && (fd = open (device, O_RDONLY | O_EXCL | O_NONBLOCK)) < 0) {
-		return -1;
-	}
-
-	get_read_write_speed (fd, &read_speed, &write_speed);
-	close (fd);
-	max_speed = (int)floor  (write_speed) / CD_ROM_SPEED;
-
-	return max_speed;
 }
 
 static char *
