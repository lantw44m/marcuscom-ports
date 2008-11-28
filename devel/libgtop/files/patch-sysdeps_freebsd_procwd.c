--- sysdeps/freebsd/procwd.c.orig	2008-11-28 02:26:20.000000000 -0500
+++ sysdeps/freebsd/procwd.c	2008-11-28 02:26:51.000000000 -0500
@@ -131,6 +131,9 @@ glibtop_get_proc_wd_s(glibtop *server, g
 	dirs = g_ptr_array_sized_new(1);
 
 	for (i = 0; i < len / sizeof(*kif); i++, kif++) {
+		if (kif->kf_structsize != sizeof(*kif))
+			continue;
+
 		switch (kif->kf_fd) {
 			case KF_FD_TYPE_ROOT:
 				g_strlcpy(buf->root, kif->kf_path,
