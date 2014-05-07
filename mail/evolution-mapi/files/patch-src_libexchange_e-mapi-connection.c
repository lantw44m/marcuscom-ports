diff --git a/src/libexchangemapi/e-mapi-connection.c b/src/libexchangemapi/e-mapi-connection.c
index dc73408..5ae1aab 100644
--- src/libexchangemapi/e-mapi-connection.c.orig
+++ src/libexchangemapi/e-mapi-connection.c
@@ -3756,7 +3756,7 @@ add_object_recipients (EMapiConnection *conn,
 
 	count = 0;
 	for (recipient = recipients, ii = 0; recipient; recipient = recipient->next, ii++) {
-		if (!e_mapi_util_find_array_propval (&recipient->properties, PidTagPrimarySmtpAddress)
+		if (!e_mapi_util_find_array_propval (&recipient->properties, PidTagSmtpAddress)
 		    && !e_mapi_util_find_array_propval (&recipient->properties, PidTagDisplayName))
 			g_debug ("%s: Cannot get email or display name for a recipient %d, skipping it", G_STRFUNC, ii);
 		else
@@ -3777,7 +3777,7 @@ add_object_recipients (EMapiConnection *conn,
 	}
 
 	for (ii = 0, jj = 0, recipient = recipients; ii < count && recipient != NULL; ii++, recipient = recipient->next) {
-		users[ii] = e_mapi_util_find_array_propval (&recipient->properties, PidTagPrimarySmtpAddress);
+		users[ii] = e_mapi_util_find_array_propval (&recipient->properties, PidTagSmtpAddress);
 		if (!users[ii])
 			users[ii] = e_mapi_util_find_array_propval (&recipient->properties, PidTagDisplayName);
 		if (!users[ii]) {
