--- src/vte.c.orig	Tue Mar  4 14:25:26 2003
+++ src/vte.c	Wed Mar 26 01:42:42 2003
@@ -7320,7 +7320,7 @@
 	if (condition & G_IO_IN) {
 		bcount = sizeof(buf) -
 			 _vte_buffer_length(terminal->pvt->incoming);
-		bcount = read(fd, buf, MAX(bcount, sizeof(buf) / 2));
+		bcount = read(fd, buf, MAX(bcount, (int)(sizeof(buf) / 2)));
 	}
 	eof = FALSE;
 	if (condition & G_IO_HUP) {
