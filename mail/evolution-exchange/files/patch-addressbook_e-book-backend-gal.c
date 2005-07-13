--- addressbook/e-book-backend-gal.c.orig	Wed Jul 13 18:41:36 2005
+++ addressbook/e-book-backend-gal.c	Wed Jul 13 18:41:59 2005
@@ -423,12 +423,13 @@ get_contact_handler (LDAPOp *op, LDAPMes
 	   the op after either */
 	msg_type = ldap_msgtype (res);
 	if (msg_type == LDAP_RES_SEARCH_ENTRY) {
+		LDAPMessage *e;
+		EContact *contact;
+		char *vcard;
 		g_mutex_lock (bl->priv->ldap_lock);
-		LDAPMessage *e = ldap_first_entry(bl->priv->ldap, res);
+		e = ldap_first_entry(bl->priv->ldap, res);
 		g_mutex_unlock (bl->priv->ldap_lock);
 
-		EContact *contact;
-		char *vcard;
 
 		if (!e) {
 			g_warning ("uh, this shouldn't happen");
