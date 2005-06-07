--- providers/sqlite/gda-sqlite-provider.c.orig	Tue Jun  7 16:22:30 2005
+++ providers/sqlite/gda-sqlite-provider.c	Tue Jun  7 16:21:28 2005
@@ -1087,8 +1087,8 @@ get_types (GdaConnection *cnc, GdaParame
 					Column *column = &(table->aCol[j]);
 					
 					if (column->zType && !g_hash_table_lookup (names, column->zType)) {
-						g_hash_table_insert (names, g_strdup (column->zType), GINT_TO_POINTER (1));
 						GdaValueType type;
+						g_hash_table_insert (names, g_strdup (column->zType), GINT_TO_POINTER (1));
 						switch (column->affinity) {
 						case SQLITE_AFF_INTEGER:
 							type = GDA_VALUE_TYPE_INTEGER;
