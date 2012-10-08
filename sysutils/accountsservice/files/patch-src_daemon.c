--- src/daemon.c.orig	2012-08-16 19:03:51.000000000 +0000
+++ src/daemon.c	2012-10-08 09:18:14.000000000 +0000
@@ -68,6 +68,7 @@
         "nobody4",
         "noaccess",
         "postgres",
+        "pgsql",
         "pvm",
         "rpm",
         "nfsnobody",
@@ -77,6 +78,7 @@
         "games",
         "man",
         "at",
+        "saned",
         NULL
 };
 
@@ -304,7 +306,11 @@
 
         /* Every iteration */
         fp = *state;
+#ifdef HAVE_FGETPWENT
         pwent = fgetpwent (fp);
+#else
+	pwent = getpwent ();
+#endif
         if (pwent != NULL) {
                 return pwent;
         }
