--- sysdeps/freebsd/procopenfiles.c.orig	2008-11-28 02:24:59.000000000 -0500
+++ sysdeps/freebsd/procopenfiles.c	2008-11-28 02:26:12.000000000 -0500
@@ -293,6 +293,9 @@ glibtop_get_proc_open_files_s (glibtop *
 	for (i = 0; i < len / sizeof(*kif); i++, kif++) {
 		glibtop_open_files_entry entry = {0};
 
+		if (kif->kf_structsize != sizeof(*kif))
+			continue;
+
 		if (kif->kf_fd < 0)
 			continue;
 
