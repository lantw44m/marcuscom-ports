--- src/bugzilla.c.orig	Thu Feb 10 06:01:10 2005
+++ src/bugzilla.c	Fri May 20 15:17:09 2005
@@ -40,7 +40,8 @@
 #include <libgnomevfs/gnome-vfs.h>
 
 #include <libgnome/gnome-desktop-item.h>
-#include <menu-tree.h>
+#define  GMENU_I_KNOW_THIS_IS_UNSTABLE
+#include <gmenu-tree.h>
 
 #include <bonobo/bonobo-exception.h>
 #include <bonobo-activation/bonobo-activation.h>
@@ -1123,32 +1124,74 @@ NULL)) {
 }
 
 static int
-compare_applications (MenuTreeEntry *a,
-		      MenuTreeEntry *b)
+compare_applications (GMenuTreeEntry *a,
+		      GMenuTreeEntry *b)
 {
-	return g_utf8_collate (menu_tree_entry_get_name (a),
-			       menu_tree_entry_get_name (b));
+	return g_utf8_collate (gmenu_tree_entry_get_name (a),
+			       gmenu_tree_entry_get_name (b));
 }
 
+static GSList *get_all_applications_from_dir (GMenuTreeDirectory *directory,
+					      GSList             *list);
+
 static GSList *
-get_all_applications_from_dir (MenuTreeDirectory *directory,
-			       GSList            *list)
+get_all_applications_from_alias (GMenuTreeAlias *alias,
+				 GSList         *list)
 {
-	GSList *subdirs;
+	GMenuTreeItem *aliased_item;
+
+	aliased_item = gmenu_tree_alias_get_item (alias);
+
+	switch (gmenu_tree_item_get_type (aliased_item)) {
+	case GMENU_TREE_ITEM_DIRECTORY:
+		list = get_all_applications_from_dir (GMENU_TREE_DIRECTORY (aliased_item), list);
+		break;
+
+	case GMENU_TREE_ITEM_ENTRY:
+		list = g_slist_append (list, gmenu_tree_item_ref (aliased_item));
+		break;
+
+	default:
+		break;
+	}
+
+	gmenu_tree_item_unref (aliased_item);
+
+	return list;
+}
+
+static GSList *
+get_all_applications_from_dir (GMenuTreeDirectory *directory,
+			       GSList             *list)
+{
+	GSList *items;
 	GSList *l;
 
-	list = g_slist_concat (list,
-			       menu_tree_directory_get_entries (directory));
+	items = gmenu_tree_directory_get_contents (directory);
+	for (l = items; l; l = l->next) {
+		GMenuTreeItem *item = l->data;
 
-	subdirs = menu_tree_directory_get_subdirs (directory);
-	for (l = subdirs; l; l = l->next) {
-		MenuTreeDirectory *subdir = l->data;
+		switch (gmenu_tree_item_get_type (item)) {
+		case GMENU_TREE_ITEM_DIRECTORY:
+			list = get_all_applications_from_dir (GMENU_TREE_DIRECTORY (item), list);
+			break;
 
-		list = get_all_applications_from_dir (subdir, list);
+		case GMENU_TREE_ITEM_ENTRY:
+			list = g_slist_append (list, gmenu_tree_item_ref (item));
+			break;
 
-		menu_tree_directory_unref (subdir);
+		case GMENU_TREE_ITEM_ALIAS:
+			list = get_all_applications_from_alias (GMENU_TREE_ALIAS (item), list);
+			break;
+
+		default:
+			break;
+		}
+
+		gmenu_tree_item_unref (item);
 	}
-	g_slist_free (subdirs);
+
+	g_slist_free (items);
 
 	return list;
 }
@@ -1156,18 +1199,18 @@ get_all_applications_from_dir (MenuTreeD
 static GSList *
 get_all_applications (void)
 {
-	MenuTree          *tree;
-	MenuTreeDirectory *root;
-	GSList            *retval;
+	GMenuTree          *tree;
+	GMenuTreeDirectory *root;
+	GSList             *retval;
 
-	tree = menu_tree_lookup ("applications.menu");
+	tree = gmenu_tree_lookup ("applications.menu", GMENU_TREE_FLAGS_NONE);
 
-	root = menu_tree_get_root_directory (tree);
+	root = gmenu_tree_get_root_directory (tree);
 
 	retval = get_all_applications_from_dir (root, NULL);
 
-	menu_tree_directory_unref (root);
-	menu_tree_unref (tree);
+	gmenu_tree_item_unref (root);
+	gmenu_tree_unref (tree);
 
 	retval = g_slist_sort (retval, (GCompareFunc) compare_applications);
 
@@ -1193,28 +1236,28 @@ load_applications (void)
 	for (l = all_applications; l; l = l->next) {
 		GnomeDesktopItem *ditem;
 		char *icon;
-		MenuTreeEntry *entry = l->data;
+		GMenuTreeEntry *entry = l->data;
 
-		if (prev_name && strcmp (menu_tree_entry_get_name (entry), prev_name) == 0) {
-			menu_tree_entry_unref (entry);
+		if (prev_name && strcmp (gmenu_tree_entry_get_name (entry), prev_name) == 0) {
+			gmenu_tree_item_unref (entry);
 			continue;
 		}
-		ditem = gnome_desktop_item_new_from_uri (menu_tree_entry_get_desktop_file_path (entry), 
+		ditem = gnome_desktop_item_new_from_uri (gmenu_tree_entry_get_desktop_file_path (entry), 
 							 0, &error);
 		if (!ditem) {
 			if (error) {
-				g_warning ("Couldn't load %s: %s", desktop_entry_get_path (entry),
+				g_warning ("Couldn't load %s: %s", gmenu_tree_entry_get_desktop_file_path (entry),
 					   error->message);
 				g_error_free (error);
 				error = NULL;
 			}
-			menu_tree_entry_unref (entry);
+			gmenu_tree_item_unref (entry);
 			continue;
 		}
     
 		if ((gnome_desktop_item_get_entry_type (ditem) != GNOME_DESKTOP_ITEM_TYPE_APPLICATION) || !gnome_desktop_item_get_string (ditem, BUGZILLA_BUGZILLA)) {
 			gnome_desktop_item_unref (ditem);	
-			menu_tree_entry_unref (entry);
+			gmenu_tree_item_unref (entry);
 			continue;
 		}
 
@@ -1231,9 +1274,9 @@ load_applications (void)
 			gnome_desktop_item_get_string (ditem, GNOME_DESKTOP_ITEM_EXEC),
 			gnome_desktop_item_get_string (ditem, BUGZILLA_OTHER_BINARIES));
 		g_free (icon);
-		prev_name = menu_tree_entry_get_name (entry);
+		prev_name = gmenu_tree_entry_get_name (entry);
 		gnome_desktop_item_unref (ditem);	
-		menu_tree_entry_unref (entry);
+		gmenu_tree_item_unref (entry);
 	}
 	g_slist_free (all_applications);
 
