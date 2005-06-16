--- calendar/gui/dialogs/meeting-page.c.orig	Wed Jun 15 16:34:21 2005
+++ calendar/gui/dialogs/meeting-page.c	Wed Jun 15 16:34:35 2005
@@ -933,8 +933,8 @@ meeting_page_construct (MeetingPage *mpa
 	for (it = e_list_get_iterator((EList *)priv->accounts);
 	     e_iterator_is_valid(it);
 	     e_iterator_next(it)) {
-		a = (EAccount *)e_iterator_get(it);
 		char *full;
+		a = (EAccount *)e_iterator_get(it);
 		
 		full = g_strdup_printf("%s <%s>", a->id->name, a->id->address);
 
