--- src/af/xap/unix/xap_UnixDlg_Insert_Symbol.cpp.orig	Wed Feb 11 13:49:15 2004
+++ src/af/xap/unix/xap_UnixDlg_Insert_Symbol.cpp	Wed Feb 11 13:50:09 2004
@@ -487,6 +487,7 @@
 GtkWidget * XAP_UnixDialog_Insert_Symbol::_constructWindow(void)
 {
 	GtkWidget * vboxInsertS;
+	GtkWidget * chapters;
 
 	ConstructWindowName();
 
@@ -517,7 +518,8 @@
 					   m_areaCurrentSym, TRUE, FALSE, 0);
 #else
 
-	m_SymbolMap = gucharmap_charmap_new ();
+	chapters = gucharmap_block_chapters_new ();
+	m_SymbolMap = gucharmap_charmap_new (GUCHARMAP_CHAPTERS (chapters));
 	gtk_widget_show (m_SymbolMap);
 	gtk_box_pack_start(GTK_BOX(vboxInsertS), m_SymbolMap, TRUE, TRUE, 0);
 
