--- control-center/control-center-categories.c	2005/02/03 21:59:49	1.5
+++ control-center/control-center-categories.c	2005/05/02 08:05:27	1.9
@@ -33,8 +33,8 @@
 #include <glib/gi18n.h>
 #include <gtk/gtk.h>
 
-#define MENU_I_KNOW_THIS_IS_UNSTABLE
-#include <menu-tree.h>
+#define GMENU_I_KNOW_THIS_IS_UNSTABLE
+#include <gmenu-tree.h>
 
 static char *
 remove_icon_suffix (const char *icon)
@@ -87,17 +87,17 @@
 
 static ControlCenterEntry *
 control_center_entry_new (ControlCenterCategory *category,
-			  MenuTreeEntry         *menu_entry)
+			  GMenuTreeEntry        *menu_entry)
 {
 	ControlCenterEntry *retval;
 
 	retval = g_new0 (ControlCenterEntry, 1);
 
 	retval->category      = category;
-	retval->title         = g_strdup (menu_tree_entry_get_name (menu_entry));
-	retval->comment       = g_strdup (menu_tree_entry_get_comment (menu_entry));
-	retval->desktop_entry = g_strdup (menu_tree_entry_get_desktop_file_path (menu_entry));
-	retval->icon_pixbuf   = load_icon (menu_tree_entry_get_icon (menu_entry));
+	retval->title         = g_strdup (gmenu_tree_entry_get_name (menu_entry));
+	retval->comment       = g_strdup (gmenu_tree_entry_get_comment (menu_entry));
+	retval->desktop_entry = g_strdup (gmenu_tree_entry_get_desktop_file_path (menu_entry));
+	retval->icon_pixbuf   = load_icon (gmenu_tree_entry_get_icon (menu_entry));
 
 	return retval;
 }
@@ -125,25 +125,27 @@
 
 static void
 populate_category (ControlCenterCategory *category,
-		   MenuTreeDirectory     *menu_directory)
+		   GMenuTreeDirectory    *menu_directory)
 {
-	GSList *menu_entries;
+	GSList *items;
 	GSList *entries;
 	GSList *l;
 
 	entries = NULL;
 
-	menu_entries = menu_tree_directory_get_entries (menu_directory);
-	for (l = menu_entries; l; l = l->next) {
-		MenuTreeEntry *menu_entry = l->data;
+	items = gmenu_tree_directory_get_contents (menu_directory);
+	for (l = items; l; l = l->next) {
+		GMenuTreeItem *item = l->data;
+
+		if (gmenu_tree_item_get_type (item) == GMENU_TREE_ITEM_ENTRY)
+			entries = g_slist_append (entries,
+						  control_center_entry_new (category,
+									    GMENU_TREE_ENTRY (item)));
 
-		entries = g_slist_prepend (entries,
-					   control_center_entry_new (category, menu_entry));
-
-		menu_tree_entry_unref (menu_entry);
+		gmenu_tree_item_unref (item);
 	}
 
-	g_slist_free (menu_entries);
+	g_slist_free (items);
 
 	if (entries != NULL) {
 		GSList *l;
@@ -160,15 +162,15 @@
 }
 
 static ControlCenterCategory *
-control_center_category_new (MenuTreeDirectory *menu_directory,
-			     const char        *title,
-			     gboolean           real_category)
+control_center_category_new (GMenuTreeDirectory *menu_directory,
+			     const char         *title,
+			     gboolean            real_category)
 {
 	ControlCenterCategory *retval;
 
 	retval = g_new0 (ControlCenterCategory, 1);
 
-	retval->title         = g_strdup (title ? title : menu_tree_directory_get_name (menu_directory));
+	retval->title         = g_strdup (title ? title : gmenu_tree_directory_get_name (menu_directory));
 	retval->real_category = real_category != FALSE;
 
 	populate_category (retval, menu_directory);
@@ -193,25 +195,31 @@
 }
 
 static GSList *
-read_categories_from_menu_directory (MenuTreeDirectory *directory,
-				     GSList            *categories)
+read_categories_from_menu_directory (GMenuTreeDirectory *directory,
+				     GSList             *categories)
 {
-	GSList *subdirs;
+	GSList *items;
 	GSList *l;
 
-	subdirs = menu_tree_directory_get_subdirs (directory);
-	for (l = subdirs; l; l = l->next) {
-		MenuTreeDirectory *subdir = l->data;
+	items = gmenu_tree_directory_get_contents (directory);
+	for (l = items; l; l = l->next) {
+		GMenuTreeItem *item = l->data;
+
+		if (gmenu_tree_item_get_type (item) == GMENU_TREE_ITEM_DIRECTORY) {
+			GMenuTreeDirectory *subdir;
 
-		categories = g_slist_prepend (categories,
-					      control_center_category_new (subdir, NULL, TRUE));
+			subdir = GMENU_TREE_DIRECTORY (item);
 
-		categories = read_categories_from_menu_directory (subdir, categories);
+			categories = g_slist_prepend (categories,
+						      control_center_category_new (subdir, NULL, TRUE));
+
+			categories = read_categories_from_menu_directory (subdir, categories);
+		}
 
-		menu_tree_directory_unref (subdir);
+		gmenu_tree_item_unref (item);
 	}
 
-	g_slist_free (subdirs);
+	g_slist_free (items);
 
 	return categories;
 }
@@ -227,17 +235,17 @@
 control_center_get_information (void)
 {
 	ControlCenterInformation *information;
-	MenuTree                 *menu_tree;
-	MenuTreeDirectory        *menu_root;
+	GMenuTree                *menu_tree;
+	GMenuTreeDirectory       *menu_root;
 	GSList                   *categories;
 	GSList                   *prev, *curr;
 
 	information = g_new0 (ControlCenterInformation, 1);
 
-	menu_tree = menu_tree_lookup ("preferences.menu");
+	menu_tree = gmenu_tree_lookup ("preferences.menu", GMENU_TREE_FLAGS_NONE);
 
-	if (!(menu_root = menu_tree_get_root_directory (menu_tree))) {
-		menu_tree_unref (menu_tree);
+	if (!(menu_root = gmenu_tree_get_root_directory (menu_tree))) {
+		gmenu_tree_unref (menu_tree);
 		return information;
 	}
 
@@ -257,7 +265,7 @@
 		}
 	}
 
-	menu_tree_directory_unref (menu_root);
+	gmenu_tree_item_unref (menu_root);
 
 	if (categories != NULL) {
 		GSList *l;
@@ -272,7 +280,7 @@
 		g_slist_free (categories);
 	}
 
-	menu_tree_unref (menu_tree);
+	gmenu_tree_unref (menu_tree);
 
 	return information;
 }

