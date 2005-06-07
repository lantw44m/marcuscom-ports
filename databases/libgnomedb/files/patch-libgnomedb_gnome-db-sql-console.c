--- libgnomedb/gnome-db-sql-console.c.orig	Tue Jun  7 16:36:48 2005
+++ libgnomedb/gnome-db-sql-console.c	Tue Jun  7 16:36:57 2005
@@ -534,8 +534,8 @@ run_internal_cmde (GnomeDbSqlConsole *co
 
 	/* help */
 	if (!cmde_ok && !strcmp (pcmde, "?")) {
-		cmde_ok = TRUE;
 		GString *string;
+		cmde_ok = TRUE;
 
 		string = g_string_new (_("SQL statements:\n"
 					 "  they can span several lines, and are executed\n"
