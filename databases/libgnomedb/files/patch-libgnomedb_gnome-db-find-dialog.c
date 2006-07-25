
$FreeBSD: ports/databases/libgnomedb/files/patch-libgnomedb_gnome-db-find-dialog.c,v 1.3 2005/11/10 16:03:00 vs Exp $

--- libgnomedb/gnome-db-find-dialog.c.orig
+++ libgnomedb/gnome-db-find-dialog.c
@@ -220,12 +220,14 @@
 	
 	g_object_ref (dm);
 	
+	{
 	GnomeDbFindDialog *dialog = gnome_db_find_dialog_new (title);
 	gnome_db_find_dialog_add_fields_from_model (dialog, dm);
 
 	g_object_unref (dm);
 
 	return dialog;
+	}
 }
 
 /**
