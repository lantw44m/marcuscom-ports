--- pam/gkr-pam-module.c.orig	2009-07-09 04:01:56.000000000 +0200
+++ pam/gkr-pam-module.c	2009-07-18 22:17:40.000000000 +0200
@@ -229,8 +229,10 @@ evaluate_inlist (const char *needle, con
 	const char *item;
 	const char *remaining;
 
+#if defined(PAM_BAD_ITEM)
 	if (!needle)
 		return PAM_BAD_ITEM;
+#endif
 
 	remaining = haystack;
 
@@ -255,7 +257,10 @@ evaluate_inlist (const char *needle, con
 		++remaining;
         }
 
+#if defined(PAM_BAD_ITEM)
         return PAM_BAD_ITEM;
+#endif
+
 }
 
 /* -----------------------------------------------------------------------------
