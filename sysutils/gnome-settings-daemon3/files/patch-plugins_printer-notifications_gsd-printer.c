--- plugins/print-notifications/gsd-printer.c.orig	2011-09-19 21:15:52.000000000 +0200
+++ plugins/print-notifications/gsd-printer.c	2011-09-19 21:17:08.000000000 +0200
@@ -771,6 +771,7 @@ set_default_paper_size (const gchar *pri
         }
 
         /* Set default PaperSize according to the locale */
+#if 0
         locale = setlocale (LC_PAPER, NULL);
         if (!locale)
                 locale = setlocale (LC_MESSAGES, NULL);
@@ -779,6 +780,7 @@ set_default_paper_size (const gchar *pri
                 g_object_unref (proxy);
                 return;
         }
+#endif
 
         /* CLDR 2.0 alpha
          * http://unicode.org/repos/cldr-tmp/trunk/diff/supplemental/territory_language_information.html
