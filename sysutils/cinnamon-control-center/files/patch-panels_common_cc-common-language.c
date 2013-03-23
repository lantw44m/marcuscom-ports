--- panels/common/cc-common-language.orig.c	2013-02-28 12:16:01.054493856 +0100
+++ panels/common/cc-common-language.c	2013-02-28 12:16:14.526494237 +0100
@@ -580,7 +580,7 @@
                             &error )) {
                 g_debug ("Couldn't get available languages: %s", error->message);
                 g_error_free (error);
-                return;
+                return ht;
         }
 
         name = strtok (avail_languages, "\n");
