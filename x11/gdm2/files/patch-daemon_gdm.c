--- daemon/gdm.c.orig	Tue Jun 10 19:25:11 2003
+++ daemon/gdm.c	Mon Jun 16 16:48:29 2003
@@ -38,7 +38,7 @@
 #include <locale.h>
 
 /* This should be moved to auth.c I suppose */
-#include <X11/Xauth.h>
+/*#include <X11/Xauth.h>*/
 
 #include <vicious.h>
 
@@ -1216,7 +1216,9 @@
 	gdm_final_cleanup ();
 	chdir ("/");
 
+#ifdef __linux__
 	change_to_first_and_clear (TRUE /* reboot */);
+#endif
 
 	argv = ve_split (GdmRebootReal);
 	execv (argv[0], argv);
@@ -1234,7 +1236,9 @@
 	gdm_final_cleanup ();
 	chdir ("/");
 
+#ifdef __linux__
 	change_to_first_and_clear (FALSE /* reboot */);
+#endif
 
 	argv = ve_split (GdmHaltReal);
 	execv (argv[0], argv);
