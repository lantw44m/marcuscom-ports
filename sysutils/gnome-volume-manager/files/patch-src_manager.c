--- src/manager.c.orig	Tue Nov  7 13:01:17 2006
+++ src/manager.c	Tue Nov  7 21:18:25 2006
@@ -23,9 +23,12 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <dirent.h>
+#include <fcntl.h>
 #include <signal.h>
 #include <unistd.h>
 #include <utmp.h>
+#include <sys/param.h>
+#include <sys/mount.h>
 
 #include <locale.h>
 
@@ -3185,6 +3188,12 @@ gvm_local_user (void)
 	size_t n;
 	DIR *dir;
 	int vt;
+#ifndef __linux__
+	int bytes, fd;
+	struct stat sb;
+	struct utmp buf[1024];
+	size_t len;
+#endif
 	
 	if (local & LOCAL_USER_CHECKED)
 		return (local & LOCAL_USER_FOUND);
@@ -3208,6 +3217,7 @@ gvm_local_user (void)
 	
  fallback:
 	
+#ifdef __linux__
 	if (!(local & LOCAL_USER_FOUND)) {
 		setutent ();
 		
@@ -3222,6 +3232,29 @@ gvm_local_user (void)
 		
 		endutent ();
 	}
+#else
+	if ((fd = open (_PATH_WTMP, O_RDONLY, 0)) < 0 || fstat(fd, &sb) == -1) {
+		close (fd);
+		return TRUE;
+	}
+
+	len = (sb.st_size + sizeof(buf) - 1) / sizeof(buf);
+
+	while (!local && --len >= 0) {
+		if (lseek(fd, (off_t) (len * sizeof(buf)), L_SET) == -1 ||
+				(bytes = read (fd, buf, sizeof(buf))) == -1) {
+			close (fd);
+			return TRUE;
+		}
+		for (utmp = &buf[bytes / sizeof(buf[0]) - 1]; !local && utmp >= buf; --utmp) {
+			if (!utmp->ut_name[0] || strncmp (utmp->ut_name, user, n) != 0)
+				continue;
+			local = utmp->ut_line[0] == ':' && utmp->ut_line[1] >= '0' && utmp->ut_line[1] <= '9' || !strncmp (utmp->ut_line, "tty", 3) ? LOCAL_USER_FOUND : 0;
+		}
+	}
+
+	close (fd);
+#endif
 	
 	local |= LOCAL_USER_CHECKED;
 	
