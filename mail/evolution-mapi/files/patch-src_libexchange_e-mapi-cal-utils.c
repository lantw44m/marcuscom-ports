--- src/libexchangemapi/e-mapi-cal-utils.c.orig	2014-03-24 09:28:56.000000000 +0000
+++ src/libexchangemapi/e-mapi-cal-utils.c	2014-05-07 09:56:54.788424673 +0000
@@ -462,6 +462,7 @@
 	gchar *start = NULL, *end = NULL;
 	time_t start_date, end_date;
 	icalcomponent *icalcomp = NULL;
+	int daylight;
 
 	if (!bin)
 		return;
@@ -686,11 +687,10 @@
 		PidTagNickname,
 		PidTagRecipientDisplayName,
 		PidTagDisplayName,
-		PidTag7BitDisplayName
+		PidTagAddressBookDisplayNamePrintable
 	};
 
 	const uint32_t email_proptags[] = {
-		PidTagPrimarySmtpAddress,
 		PidTagSmtpAddress
 	};
 
@@ -1352,7 +1352,6 @@
 		set_value (PidTagEmailAddress, email);
 
 		set_value (PidTagSmtpAddress, email);
-		set_value (PidTagPrimarySmtpAddress, email);
 
 		ui32 = 0;
 		set_value (PidTagSendInternetEncoding, &ui32);
@@ -1433,9 +1432,7 @@
 
 		set_value (PidTagAddressType, "SMTP");
 		set_value (PidTagEmailAddress, email);
-
 		set_value (PidTagSmtpAddress, email);
-		set_value (PidTagPrimarySmtpAddress, email);
 
 		ui32 = 0;
 		set_value (PidTagSendInternetEncoding, &ui32);
