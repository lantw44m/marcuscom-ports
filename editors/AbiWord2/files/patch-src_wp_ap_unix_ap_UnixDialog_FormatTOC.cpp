--- src/wp/ap/unix/ap_UnixDialog_FormatTOC.cpp.orig	Sun Mar 28 15:54:04 2004
+++ src/wp/ap/unix/ap_UnixDialog_FormatTOC.cpp	Sun Mar 28 15:55:46 2004
@@ -532,11 +532,11 @@
 	{
 		sVal = new UT_String(static_cast<char *>(vecTypeList->getNthItem(j)));
 		m_vecAllPropVals.addItem(static_cast<void *>(sVal));
-		const gchar * szLab = static_cast<const gchar *>(vecTypeList->getNthItem(j));
+		const gchar * szLab = (const gchar *)(vecTypeList->getNthItem(j));
 		UT_DEBUGMSG(("Got label %s for item %d \n",szLab,j));
 		GtkWidget * pW = gtk_menu_item_new_with_label(szLab);
 		g_object_set_data(G_OBJECT(pW),"toc-prop",(gpointer)(sProp->c_str()));
-		const gchar * szVal = static_cast<const gchar *>(vecPropList->getNthItem(j));
+		const gchar * szVal = (const gchar *)(vecPropList->getNthItem(j));
 		g_object_set_data(G_OBJECT(pW),"toc-val",(gpointer)(szVal));
 		g_signal_connect(G_OBJECT(pW),
 			   "activate",
@@ -558,7 +558,7 @@
 		m_vecAllPropVals.addItem(static_cast<void *>(sVal));
 		GtkWidget * pW = gtk_menu_item_new_with_label(static_cast<char *>(vecTypeList->getNthItem(j)));
 		g_object_set_data(G_OBJECT(pW),"toc-prop",(gpointer)sProp->c_str());
-		const gchar * szVal = static_cast<const gchar *>(vecPropList->getNthItem(j));
+		const gchar * szVal = (const gchar *)(vecPropList->getNthItem(j));
 		g_object_set_data(G_OBJECT(pW),"toc-val",(gpointer)(szVal));
 		g_signal_connect(G_OBJECT(pW),
 						 "activate",
@@ -586,7 +586,7 @@
 		m_vecAllPropVals.addItem(static_cast<void *>(sProp));
 		sVal = new UT_String(static_cast<char *>(vecProps->getNthItem(j)));
 		m_vecAllPropVals.addItem(static_cast<void *>(sVal));
-		const gchar * szLab = static_cast<const gchar *>(vecLabels->getNthItem(j));
+		const gchar * szLab = (const gchar *)(vecLabels->getNthItem(j));
 		UT_DEBUGMSG(("Got label %s for item %d \n",szLab,j));
 		GtkWidget * pW = gtk_menu_item_new_with_label(szLab);
 		g_object_set_data(G_OBJECT(pW),"toc-prop",(gpointer)(sProp->c_str()));
