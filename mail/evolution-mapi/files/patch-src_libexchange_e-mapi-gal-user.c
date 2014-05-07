diff --git a/src/configuration/e-mapi-search-gal-user.c b/src/configuration/e-mapi-search-gal-user.c
index bc084be..1512d2a 100644
--- src/configuration/e-mapi-search-gal-user.c.orig
+++ src/configuration/e-mapi-search-gal-user.c
@@ -270,8 +270,8 @@ build_gal_search_restriction_cb (EMapiConnection *conn,
 
 	restriction->res.resOr.res[1].rt = RES_CONTENT;
 	restriction->res.resOr.res[1].res.resContent.fuzzy = FL_SUBSTRING | FL_IGNORECASE;
-	restriction->res.resOr.res[1].res.resContent.ulPropTag = PidTagPrimarySmtpAddress;
-	restriction->res.resOr.res[1].res.resContent.lpProp.ulPropTag = PidTagPrimarySmtpAddress;
+	restriction->res.resOr.res[1].res.resContent.ulPropTag = PidTagSmtpAddress;
+	restriction->res.resOr.res[1].res.resContent.lpProp.ulPropTag = PidTagSmtpAddress;
 	restriction->res.resOr.res[1].res.resContent.lpProp.value.lpszW = talloc_strdup (mem_ctx, search_text);
 
 	*restrictions = restriction;
@@ -316,7 +316,7 @@ search_gal_build_properties_cb (EMapiConnection *conn,
 
 	SPropTagArray_add (mem_ctx, props, PidTagEntryId);
 	SPropTagArray_add (mem_ctx, props, PidTagDisplayName);
-	SPropTagArray_add (mem_ctx, props, PidTagPrimarySmtpAddress);
+	SPropTagArray_add (mem_ctx, props, PidTagSmtpAddress);
 	SPropTagArray_add (mem_ctx, props, PidTagEmailAddress);
 
 	return TRUE;
@@ -341,7 +341,7 @@ transfer_gal_search_objects_cb (EMapiConnection *conn,
 	g_return_val_if_fail (sid != NULL, FALSE);
 
 	display_name = e_mapi_util_find_array_propval (&object->properties, PidTagDisplayName);
-	email = e_mapi_util_find_array_propval (&object->properties, PidTagPrimarySmtpAddress);
+	email = e_mapi_util_find_array_propval (&object->properties, PidTagSmtpAddress);
 	entry_id = e_mapi_util_find_array_propval (&object->properties, PidTagEntryId);
 	user_dn = e_mapi_util_find_array_propval (&object->properties, PidTagEmailAddress);
 
