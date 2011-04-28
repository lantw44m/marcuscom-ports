--- panels/printers/pp-new-printer-dialog.c.orig	2011-04-27 23:34:53.000000000 +0200
+++ panels/printers/pp-new-printer-dialog.c	2011-04-27 23:40:18.000000000 +0200
@@ -1033,8 +1033,8 @@ new_printer_add_button_cb (GtkButton *bu
 
 
               /* Set default PaperSize according to the locale */
-              locale = setlocale (LC_PAPER, NULL);
-              if (locale == NULL)
+//              locale = setlocale (LC_PAPER, NULL);
+//              if (locale == NULL)
                 locale = setlocale (LC_MESSAGES, NULL);
 
               if (locale)
