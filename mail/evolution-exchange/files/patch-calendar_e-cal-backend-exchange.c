--- calendar/e-cal-backend-exchange.c.orig	Thu Jul 21 10:54:25 2005
+++ calendar/e-cal-backend-exchange.c	Fri Jul 29 23:06:07 2005
@@ -363,10 +363,10 @@ open_calendar (ECalBackendSync *backend,
 static ECalBackendSyncStatus
 remove_calendar (ECalBackendSync *backend, EDataCal *cal)
 {
-	d(printf("ecbe_remove_calendar(%p, %p)\n", backend, cal));
 	ECalBackendExchange *cbex = E_CAL_BACKEND_EXCHANGE (backend);
 	ExchangeAccountFolderResult result;
 	const char *uri;
+	d(printf("ecbe_remove_calendar(%p, %p)\n", backend, cal));
 
 	/* FIXME: Deleting calendar/tasks from respective views */
 	uri = e_folder_exchange_get_internal_uri (cbex->folder);
@@ -1437,6 +1437,7 @@ build_msg ( ECalBackendExchange *cbex, E
 	e_cal_component_get_uid (comp, &uid);
 	e_cal_component_get_attachment_list (comp, &attach_list);
 	for (l = attach_list; l ; l = l->next){
+		char *mime_type;
 		if (!strncmp ((char *)l->data, "file://", 7)) {
 			fname = (char *)(l->data) + strlen ("file://");
 			filename = g_strrstr (fname, "/") + 1;
@@ -1465,7 +1466,7 @@ build_msg ( ECalBackendExchange *cbex, E
 		camel_data_wrapper_construct_from_stream (wrapper, stream);
 		camel_object_unref (stream);
 
-		char *mime_type = gnome_vfs_get_mime_type (dest_url + strlen ("file://"));
+		mime_type = gnome_vfs_get_mime_type (dest_url + strlen ("file://"));
 		type = camel_content_type_decode (mime_type);
 		camel_data_wrapper_set_mime_type_field (wrapper, type);
 		camel_content_type_unref (type);
