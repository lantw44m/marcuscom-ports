--- cd-drive.c.orig	Sun Aug  1 19:58:03 2004
+++ cd-drive.c	Sun Aug  1 19:59:15 2004
@@ -484,9 +484,49 @@
 #endif /* USE_HAL */
 
 #if defined(__linux__) || defined(__FreeBSD__)
+static int
+get_device_max_write_speed (char *device)
+{
+	int fd;
+	int max_speed;
+	int read_speed, write_speed;
 
+	max_speed = -1;
 
+	fd = open (device, O_RDONLY|O_EXCL|O_NONBLOCK);
+	if (fd < 0) {
+		return -1;
+	}
 
+	get_read_write_speed (fd, &read_speed, &write_speed);
+	close (fd);
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
+
+	max_speed = -1;
+
+	fd = open (device, O_RDONLY|O_EXCL|O_NONBLOCK);
+	if (fd < 0) {
+		return -1;
+	}
+
+	get_read_write_speed (fd, &read_speed, &write_speed);
+	close (fd);
+	max_speed = (int)floor  (read_speed) / CD_ROM_SPEED;
+
+	return max_speed;
+}
+#endif
 #endif /* __linux__ || __FreeBSD__ */
 
 #if defined (__linux__)
@@ -689,49 +729,7 @@
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
-	fd = open (device, O_RDONLY|O_EXCL|O_NONBLOCK);
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
-
-	fd = open (device, O_RDONLY|O_EXCL|O_NONBLOCK);
-	if (fd < 0) {
-		return -1;
-	}
-
-	get_read_write_speed (fd, &read_speed, &write_speed);
-	close (fd);
-	max_speed = (int)floor  (write_speed) / CD_ROM_SPEED;
 
-	return max_speed;
-}
 
 static char *
 get_scsi_cd_name (int bus, int id, int lun, const char *dev,
