===================================================================
RCS file: /cvs/gnome/evolution/calendar/gui/e-tasks.c,v
retrieving revision 1.95
retrieving revision 1.96
diff -u -r1.95 -r1.96
--- calendar/gui/e-tasks.c	2004/06/02 09:33:36	1.95
+++ calendar/gui/e-tasks.c	2004/06/03 17:54:24	1.96
@@ -679,15 +679,18 @@
 {
 	ETasksPrivate *priv;
 	va_list args;
-	char sz[2048];
-	
-	va_start (args, message);
-	vsnprintf (sz, sizeof sz, message, args);
-	va_end (args);
+	char sz[2048], *msg_string = NULL;
+
+	if (message) {
+		va_start (args, message);
+		vsnprintf (sz, sizeof sz, message, args);
+		va_end (args);
+		msg_string = sz;
+	}
 
 	priv = tasks->priv;
 	
-	e_calendar_table_set_status_message (E_CALENDAR_TABLE (priv->tasks_view), sz);
+	e_calendar_table_set_status_message (E_CALENDAR_TABLE (priv->tasks_view), msg_string);
 }
 
 /* Callback from the calendar client when an error occurs in the backend */
