--- libeog/eog-metadata-reader.c.orig	Mon Feb 20 23:48:08 2006
+++ libeog/eog-metadata-reader.c	Mon Feb 20 23:48:55 2006
@@ -228,13 +228,13 @@ eog_metadata_reader_consume (EogMetadata
 
 			if (i + priv->size < len) {
                                 /* read data in one block */
-				memcpy ((void*) ((int)(priv->exif_chunk) + priv->bytes_read), (void*)&buf[i], priv->size); 
+				memcpy ((void*) ((char *)(priv->exif_chunk) + priv->bytes_read), (void*)&buf[i], priv->size); 
 				priv->state = EMR_READ;
 				i = i + priv->size - 1; /* the for-loop consumes the other byte */
 			}
 			else {
 				int chunk_len = len - i;
-				memcpy ((void*)((int)priv->exif_chunk + priv->bytes_read), (void*)&buf[i], chunk_len);
+				memcpy ((void*)((char *)priv->exif_chunk + priv->bytes_read), (void*)&buf[i], chunk_len);
 				priv->bytes_read += chunk_len; /* bytes already read */
 				priv->size = (i + priv->size) - len; /* remaining data to read */
 				i = len - 1;
@@ -257,13 +257,13 @@ eog_metadata_reader_consume (EogMetadata
 
 			if (i + priv->size < len) {
 				/* read data in one block */
-				memcpy ((void*) ((int)(priv->icc_chunk) + priv->bytes_read), (void*)&buf[i], priv->size); 
+				memcpy ((void*) ((char *)(priv->icc_chunk) + priv->bytes_read), (void*)&buf[i], priv->size); 
 				priv->state = EMR_READ;
 				i = i + priv->size - 1; /* the for-loop consumes the other byte */
 			}
 			else {
 				int chunk_len = len - i;
-				memcpy ((void*)((int)priv->icc_chunk + priv->bytes_read), (void*)&buf[i], chunk_len);
+				memcpy ((void*)((char *)priv->icc_chunk + priv->bytes_read), (void*)&buf[i], chunk_len);
 				priv->bytes_read += chunk_len; /* bytes already read */
 				priv->size = (i + priv->size) - len; /* remaining data to read */
 				i = len - 1;
@@ -283,12 +283,12 @@ eog_metadata_reader_consume (EogMetadata
 
 			if (i + priv->size < len) {
                                 /* read data in one block */
-				memcpy ((void*)((int)priv->iptc_chunk + priv->bytes_read), (void*)&buf[i], priv->size); 
+				memcpy ((void*)((char *)priv->iptc_chunk + priv->bytes_read), (void*)&buf[i], priv->size); 
 				priv->state = EMR_READ;
 			}
 			else {
 				int chunk_len = len - i;
-				memcpy ((void*)((int)priv->iptc_chunk + priv->bytes_read), (void*)&buf[i], chunk_len);
+				memcpy ((void*)((char *)priv->iptc_chunk + priv->bytes_read), (void*)&buf[i], chunk_len);
 				priv->bytes_read += chunk_len; /* bytes already read */
 				priv->size = (i + priv->size) - len; /* remaining data to read */
 				i = len - 1;
