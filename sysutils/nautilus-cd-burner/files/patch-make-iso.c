--- make-iso.c.orig	Mon Feb 28 19:34:57 2005
+++ make-iso.c	Mon Feb 28 19:36:39 2005
@@ -719,6 +719,7 @@
 	argv [i++] = "-r";
 	if (use_joliet) {
 		argv [i++] = "-J";
+		argv[i++] = "-joliet-long";
 	}
 	if (has_utf8_support) {
 		argv [i++] = "-input-charset";
@@ -806,6 +807,7 @@
 	argv [i++] = "-r";
 	if (use_joliet) {
 		argv [i++] = "-J";
+		argv[i++] = "-joliet-long";
 	}
 	if (has_utf8_support) {
 		argv [i++] = "-input-charset";
