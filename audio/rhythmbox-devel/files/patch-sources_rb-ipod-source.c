--- sources/rb-ipod-source.c.orig	Sun Sep 19 16:50:39 2004
+++ sources/rb-ipod-source.c	Sun Sep 19 16:51:22 2004
@@ -238,7 +238,7 @@
 			GValue value = {0, };
 			g_value_init (&value, G_TYPE_ULONG);
 			g_value_set_ulong (&value, song->cd_nr);
-			rhythmdb_entry_set (RHYTHMDB (db), entry, 
+			rhythmdb_entry_set (RHYTHMDB (ctxt->db), entry, 
 					    RHYTHMDB_PROP_DISC_NUMBER, 
 					    &value);
 			g_value_unset (&value);
