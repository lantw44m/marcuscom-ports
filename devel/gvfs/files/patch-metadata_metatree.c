--- metadata/metatree.c.orig	2009-07-24 15:25:43.000000000 -0400
+++ metadata/metatree.c	2009-07-24 15:24:40.000000000 -0400
@@ -896,7 +896,7 @@ verify_journal_entry (MetaJournal *journ
   if (entry_len != entry_len_end)
     return NULL;
 
-  real_crc32 = crc32 (journal->data + offset + 8, entry_len - 8);
+  real_crc32 = metadata_crc32 (journal->data + offset + 8, entry_len - 8);
   if (real_crc32 != GUINT32_FROM_BE (entry->crc32))
     return NULL;
 
@@ -1019,7 +1019,7 @@ meta_journal_entry_finish (GString *out)
   len = out->len + 4;
   append_uint32 (out, len);
   set_uint32 (out, 0, len);
-  set_uint32 (out, 4, crc32 (out->str + 8, len - 8));
+  set_uint32 (out, 4, metadata_crc32 (out->str + 8, len - 8));
   return out;
 }
 
