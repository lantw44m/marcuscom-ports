--- libgnomeprint/gnome-print-pdf.c.orig	Tue Jun 29 22:07:46 2004
+++ libgnomeprint/gnome-print-pdf.c	Tue Jun 29 22:07:55 2004
@@ -1224,9 +1224,9 @@
 static void
 gnome_print_embed_all_pdf_fonts (GnomePrintPdf *pdf)
 {
+	GList *list;
 	g_return_if_fail (pdf != NULL);
 
-	GList *list;
 
 	list = pdf->fonts;
 	while (list) {
