--- calendar/e-cal-backend-exchange-calendar.c.orig	Tue Jan 11 14:41:18 2005
+++ calendar/e-cal-backend-exchange-calendar.c	Tue Jan 11 14:41:51 2005
@@ -595,6 +595,7 @@
 	E2kHTTPStatus http_status;
 	struct _cb_data *cbdata;
 	GSList *categories;
+	char *attach_body, *attach_boundary;
 	
 	cbexc =	E_CAL_BACKEND_EXCHANGE_CALENDAR (backend);
 	
@@ -741,7 +742,6 @@
 			       from ? from : "Evolution",
 			      body_crlf);
 
-	char *attach_body, *attach_boundary;
 	build_attachment (summary, g_strdup ("This is some text\n"), NULL, &attach_body, &attach_boundary);	
 #if 0
 	msg = g_strdup_printf ("Subject: %s\r\n"
