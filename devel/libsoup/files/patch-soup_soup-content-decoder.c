--- libsoup/soup-content-decoder.c.orig	2010-03-01 03:11:09.000000000 +0100
+++ libsoup/soup-content-decoder.c	2010-03-01 03:13:01.000000000 +0100
@@ -76,6 +76,8 @@ soup_content_decoder_init (SoupContentDe
 	/* Hardcoded for now */
 	g_hash_table_insert (decoder->priv->codings, "gzip",
 			     GSIZE_TO_POINTER (SOUP_TYPE_CODING_GZIP));
+	g_hash_table_insert (decoder->priv->codings, "x-gzip",
+			     GSIZE_TO_POINTER (SOUP_TYPE_CODING_GZIP));
 }
 
 static void
