--- a11y/e-table/gal-a11y-e-cell-text.c.orig	Wed Jul 13 02:57:57 2005
+++ a11y/e-table/gal-a11y-e-cell-text.c	Wed Jul 13 02:58:28 2005
@@ -152,11 +152,12 @@ ect_get_character_at_offset (AtkText *te
 	GalA11yECell *gaec = GAL_A11Y_E_CELL (text);
 	gunichar ret_val;
 	gchar *at_offset;
+	gchar *full_text;
 
 	if (!ect_check (text))
 		return -1;
 
-	gchar *full_text = e_cell_text_get_text_by_view (gaec->cell_view, gaec->model_col, gaec->row);
+	full_text = e_cell_text_get_text_by_view (gaec->cell_view, gaec->model_col, gaec->row);
 	at_offset = g_utf8_offset_to_pointer (full_text, offset);
 	ret_val = g_utf8_get_char_validated (at_offset, -1);
 	g_free (full_text);
@@ -236,11 +237,12 @@ ect_get_character_count (AtkText *text)
 {
 	GalA11yECell *gaec = GAL_A11Y_E_CELL (text);
 	gint ret_val;
+	gchar *full_text;
 
 	if (!ect_check (text))
 		return -1;
 
-	gchar *full_text = e_cell_text_get_text_by_view (gaec->cell_view, gaec->model_col, gaec->row);
+	full_text = e_cell_text_get_text_by_view (gaec->cell_view, gaec->model_col, gaec->row);
 
 	ret_val = g_utf8_strlen (full_text, -1);
 	g_free (full_text);
