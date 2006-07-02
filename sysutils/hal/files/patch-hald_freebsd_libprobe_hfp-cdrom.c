--- hald/freebsd/libprobe/hfp-cdrom.c	7 May 2006 00:27:55 -0000	1.4
+++ hald/freebsd/libprobe/hfp-cdrom.c	2 Jul 2006 05:08:24 -0000	1.6
@@ -112,6 +112,7 @@
 
   if (cdrom->fd >= 0)		/* ATAPI transport */
     {
+#ifdef IOCATAREQUEST
       struct ata_ioc_request req;
 
       memset(&req, 0, sizeof(req));
@@ -140,6 +141,38 @@
 	    *err = hfp_strdup_printf("ATAPI error %i", req.error);
 	  return FALSE;
 	}
+#else
+      struct ata_cmd iocmd;
+
+      memset(&iocmd, 0, sizeof(iocmd));
+      iocmd.u.request.flags = ATA_CMD_ATAPI;
+      iocmd.u.request.timeout = timeout;
+      iocmd.cmd = ATAREQUEST;
+      iocmd.device = -1;
+      memcpy(iocmd.u.request.u.atapi.ccb, ccb, 16);
+
+      if (data)
+        {
+	  static int atapi_direction[] = { 0, ATA_CMD_READ, ATA_CMD_WRITE };
+
+	  iocmd.u.request.flags |= atapi_direction[direction];
+	  iocmd.u.request.data = data;
+	  iocmd.u.request.count = len;
+	}
+
+      if (ioctl(cdrom->fd, IOCATA, &iocmd) < 0)
+        {
+	  if (err)
+	    *err = hfp_strdup_printf("IOCATA failure: %s", strerror(errno));
+	  return FALSE;
+	}
+      if (iocmd.u.request.error != 0)
+        {
+	  if (err)
+	    *err = hfp_strdup_printf("ATAPI error %i", iocmd.u.request.error);
+	  return FALSE;
+	}
+#endif
     }
   else				/* SCSI transport */
     {
