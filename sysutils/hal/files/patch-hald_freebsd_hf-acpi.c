--- hald/freebsd/hf-acpi.c	4 May 2006 23:14:44 -0000	1.50
+++ hald/freebsd/hf-acpi.c	2 Jul 2006 04:38:34 -0000
@@ -114,13 +114,21 @@
       return;
     }
 
+#ifdef ACPIIO_BATT_GET_BIF
   if (ioctl(fd, ACPIIO_BATT_GET_BIF, &battif) == -1)
+#else
+  if (ioctl(fd, ACPIIO_CMBAT_GET_BIF, &battif) == -1)
+#endif
     {
       HAL_WARNING(("ioctl ACPIIO_BATT_GET_BIF failed for battery %d: %s",
         battif.unit, g_strerror(errno)));
       goto end;
     }
+#ifdef ACPIIO_BATT_GET_BST
   if (ioctl(fd, ACPIIO_BATT_GET_BST, &battst) == -1)
+#else
+  if (ioctl(fd, ACPIIO_CMBAT_GET_BST, &battst) == -1)
+#endif
     {
       HAL_WARNING(("ioctl ACPIIO_BATT_GET_BST failed for battery %d: %s",
         battst.unit, g_strerror(errno)));
