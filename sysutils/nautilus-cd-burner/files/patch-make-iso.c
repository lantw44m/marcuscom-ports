--- make-iso.c.orig	Sun Jan  9 06:49:01 2005
+++ make-iso.c	Wed Jan 12 03:11:15 2005
@@ -631,6 +631,7 @@
 	argv [i++] = "-r";
 	if (use_joliet) {
 		argv [i++] = "-J";
+		argv[i++] = "-joliet-long";
 	}
 	/* Undocumented -input-charset option */
 	argv [i++] = "-input-charset";
@@ -722,6 +723,7 @@
 	argv [i++] = "-r";
 	if (use_joliet) {
 		argv [i++] = "-J";
+		argv[i++] = "-joliet-long";
 	}
 	argv [i++] = "-input-charset";
 	argv [i++] = "utf8";
