diff --git a/src/libexchangemapi/e-mapi-book-utils.c b/src/libexchangemapi/e-mapi-book-utils.c
index 99226ff..7b70669 100644
--- src/libexchangemapi/e-mapi-book-utils.c.orig
+++ src/libexchangemapi/e-mapi-book-utils.c
@@ -95,7 +95,7 @@ static const uint32_t extra_proptags[] = {
 	PidTagStateOrProvince,
 	PidTagPostalCode,
 	PidTagCountry,
-	PidTagPrimarySmtpAddress,
+	PidTagSmtpAddress,
 	PidTagFolderId
 };
 
@@ -371,7 +371,7 @@ e_mapi_book_utils_contact_from_object (EMapiConnection *conn,
 
 	email_1 = e_contact_get (contact, E_CONTACT_EMAIL_1);
 	if (!email_1) {
-		gconstpointer value = get_proptag (PidTagPrimarySmtpAddress);
+		gconstpointer value = get_proptag (PidTagSmtpAddress);
 
 		if (value)
 			e_contact_set (contact, E_CONTACT_EMAIL_1, value);
@@ -1009,7 +1009,7 @@ func_eval_text_compare (struct _ESExp *f,
 				res->res.resOr.cRes = 4;
 				res->res.resOr.res = talloc_zero_array (esp->mem_ctx, struct mapi_SRestriction_or, res->res.resOr.cRes + 1);
 
-				proptag = PidTagPrimarySmtpAddress;
+				proptag = PidTagSmtpAddress;
 				res->res.resOr.res[0].rt = RES_CONTENT;
 				res->res.resOr.res[0].res.resContent.fuzzy = fuzzy | FL_IGNORECASE;
 				res->res.resOr.res[0].res.resContent.ulPropTag = proptag;
@@ -1115,7 +1115,7 @@ func_eval_field_exists (struct _ESExp *f,
 			res->res.resOr.res = talloc_zero_array (esp->mem_ctx, struct mapi_SRestriction_or, res->res.resOr.cRes + 1);
 
 			res->res.resOr.res[0].rt = RES_EXIST;
-			res->res.resOr.res[0].res.resExist.ulPropTag = PidTagPrimarySmtpAddress;
+			res->res.resOr.res[0].res.resExist.ulPropTag = PidTagSmtpAddress;
 
 			for (ii = 1, jj = 0; emails[jj]; jj++) {
 				proptag = get_proptag_from_field_name (emails[jj], TRUE);
