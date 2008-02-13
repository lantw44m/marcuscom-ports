--- gui/simple-greeter/gdm-languages.c.orig	2008-02-13 02:03:34.000000000 -0500
+++ gui/simple-greeter/gdm-languages.c	2008-02-13 02:05:00.000000000 -0500
@@ -347,7 +347,7 @@ select_dirs (const struct dirent *dirent
                                 struct stat st;
                                 char       *path;
 
-                                path = g_build_filename (LIBLOCALEDIR, dirent->d_name, NULL);
+                                path = g_build_filename ("/usr/share/locale", dirent->d_name, NULL);
                                 if (g_stat (path, &st) == 0) {
                                         mode = st.st_mode;
                                 }
@@ -367,7 +367,7 @@ collect_locales_from_directory (void)
         int             ndirents;
         int             cnt;
 
-        ndirents = scandir (LIBLOCALEDIR, &dirents, select_dirs, alphasort);
+        ndirents = scandir ("/usr/share/locale", &dirents, select_dirs, alphasort);
 
         for (cnt = 0; cnt < ndirents; ++cnt) {
                 char             *path;
@@ -389,7 +389,7 @@ collect_locales_from_directory (void)
                 }
 
                 /* try to get additional information from LC_IDENTIFICATION */
-                path = g_build_filename (LIBLOCALEDIR, dirents[cnt]->d_name, "LC_IDENTIFICATION", NULL);
+                path = g_build_filename ("/usr/share/locale", dirents[cnt]->d_name, "LC_IDENTIFICATION", NULL);
                 res = g_file_test (path, G_FILE_TEST_IS_REGULAR);
                 if (res) {
                         GMappedFile      *mapped;
