diff --git a/src/libexchangemapi/e-mapi-mail-utils.c b/src/libexchangemapi/e-mapi-mail-utils.c
index 479777a..0622571 100644
--- src/libexchangemapi/e-mapi-mail-utils.c.orig
+++ src/libexchangemapi/e-mapi-mail-utils.c
@@ -112,11 +112,10 @@ e_mapi_mail_utils_decode_recipients (EMapiConnection *conn,
 		PidTagNickname,
 		PidTagDisplayName,
 		PidTagRecipientDisplayName,
-		PidTag7BitDisplayName
+		PidTagAddressBookDisplayNamePrintable
 	};
 
 	const uint32_t email_proptags[] = {
-		PidTagPrimarySmtpAddress,
 		PidTagSmtpAddress
 	};
 
@@ -987,9 +986,7 @@ e_mapi_mail_add_recipients (EMapiObject *object,
 		if (email && *email) {
 			set_value (PidTagAddressType, "SMTP");
 			set_value (PidTagEmailAddress, email);
-
 			set_value (PidTagSmtpAddress, email);
-			set_value (PidTagPrimarySmtpAddress, email);
 		}
 
 		ui32 = 0;

