--- src/workbook-control-gui-priv.h.orig	Mon Aug  2 21:26:30 2004
+++ src/workbook-control-gui-priv.h	Mon Aug  2 21:27:53 2004
@@ -111,7 +111,7 @@
 void	 wbcg_insert_sheet	      (GtkWidget *ignored, WorkbookControlGUI *wbcg);
 void	 wbcg_append_sheet	      (GtkWidget *ignored, WorkbookControlGUI *wbcg);
 void	 wbcg_set_selection_halign    (WorkbookControlGUI *wbcg, StyleHAlignFlags halign);
-void	 wbcg_set_selection_valign    (WorkbookControlGUI *wbcg, StyleHAlignFlags halign);
+void	 wbcg_set_selection_valign    (WorkbookControlGUI *wbcg, StyleVAlignFlags valign);
 
 enum {
 	WBCG_MARKUP_CHANGED,
