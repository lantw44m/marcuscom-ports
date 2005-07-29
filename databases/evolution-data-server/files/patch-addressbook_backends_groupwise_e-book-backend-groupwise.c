--- addressbook/backends/groupwise/e-book-backend-groupwise.c.orig	Fri Jul 29 17:41:45 2005
+++ addressbook/backends/groupwise/e-book-backend-groupwise.c	Fri Jul 29 17:42:32 2005
@@ -1977,6 +1977,7 @@ get_contacts_from_cache (EBookBackendGro
 		printf ("\nread contacts from cache for the ids found in summary\n");
 	for (i = 0; i < ids->len; i ++) {
 		char *uid = g_ptr_array_index (ids, i);
+		EContact *contact;
 
 		g_mutex_lock (closure->mutex);
 		stopped = closure->stopped;
@@ -1985,7 +1986,7 @@ get_contacts_from_cache (EBookBackendGro
 		if (stopped)
 			break;	
 
-		EContact *contact = 
+		contact = 
 			e_book_backend_cache_get_contact (priv->cache, uid);
 		e_data_book_view_notify_update (book_view, contact);
 		g_object_unref (contact);
@@ -2652,6 +2653,12 @@ update_address_book_deltas (EBookBackend
 	EBookBackendGroupwisePrivate *priv = ebgw->priv;
 	EBookBackendCache *cache = priv->cache;
 
+	struct timeval start, end;
+	unsigned long diff;
+	const char *cache_file_name;
+	struct stat buf;
+	time_t mod_time;
+
 	if (enable_debug)
 		printf("\nupdating GroupWise system address book cache \n");
 		
@@ -2697,11 +2704,6 @@ update_address_book_deltas (EBookBackend
 		return TRUE;
 	}
 
-	struct timeval start, end;
-	unsigned long diff;
-	const char *cache_file_name;
-	struct stat buf;
-	time_t mod_time;
 
 	if (enable_debug)
 		gettimeofday(&start, NULL);
