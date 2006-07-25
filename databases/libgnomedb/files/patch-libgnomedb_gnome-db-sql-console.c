
$FreeBSD: ports/databases/libgnomedb/files/patch-libgnomedb_gnome-db-sql-console.c,v 1.1 2005/11/10 16:03:00 vs Exp $

--- libgnomedb/gnome-db-sql-console.c.orig
+++ libgnomedb/gnome-db-sql-console.c
@@ -596,8 +596,8 @@
 
 	/* help */
 	if (!cmde_ok && !strcmp (pcmde, "?")) {
-		cmde_ok = TRUE;
 		GString *string;
+		cmde_ok = TRUE;
 
 		string = g_string_new (_("SQL statements:\n"
 					 "  they can span several lines, and are executed\n"
