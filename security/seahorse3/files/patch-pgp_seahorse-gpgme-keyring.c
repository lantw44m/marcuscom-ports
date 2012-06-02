--- pgp/seahorse-gpgme-keyring.c.orig	2012-06-02 11:06:22.000000000 -0500
+++ pgp/seahorse-gpgme-keyring.c	2012-06-02 11:06:50.000000000 -0500
@@ -859,7 +859,7 @@
 {
 	SeahorseGpgmeKeyring *self = SEAHORSE_GPGME_KEYRING (object);
 
-	g_clear_object (self->pv->actions);
+	g_clear_object (&self->pv->actions);
 	g_hash_table_destroy (self->pv->keys);
 
 	/* All monitoring and scheduling should be done */
