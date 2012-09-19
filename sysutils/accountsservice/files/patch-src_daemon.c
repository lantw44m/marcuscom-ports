--- src/daemon.c.orig	2012-08-16 19:03:51.000000000 +0000
+++ src/daemon.c	2012-09-19 21:48:15.000000000 +0000
@@ -49,7 +49,7 @@
 #define PATH_SHADOW "/etc/shadow"
 #define PATH_NOLOGIN "/sbin/nologin"
 #define PATH_FALSE "/bin/false"
-#define PATH_GDM_CUSTOM "/etc/gdm/custom.conf"
+#define PATH_GDM_CUSTOM "/usr/local/etc/gdm/custom.conf"
 
 static const char *default_excludes[] = {
         "bin",
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
