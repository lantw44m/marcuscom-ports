--- sources/rb-ipod-source.c.orig	Thu Sep 16 18:03:09 2004
+++ sources/rb-ipod-source.c	Sun Sep 19 20:00:17 2004
@@ -238,7 +238,7 @@
 			GValue value = {0, };
 			g_value_init (&value, G_TYPE_ULONG);
 			g_value_set_ulong (&value, song->cd_nr);
-			rhythmdb_entry_set (RHYTHMDB (db), entry, 
+			entry_set_locked (RHYTHMDB (ctxt->db), entry, 
 					    RHYTHMDB_PROP_DISC_NUMBER, 
 					    &value);
 			g_value_unset (&value);
