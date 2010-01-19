--- src/users/user-settings.c.orig	2010-01-11 19:53:32.000000000 +0100
+++ src/users/user-settings.c	2010-01-19 14:04:14.000000000 +0100
@@ -1142,7 +1142,7 @@ on_edit_user_passwd (GtkButton *button, 
 
 	/* empty password means: don't change it */
 	if (strlen (passwd) > 0)
-		oobs_user_set_password (user, passwd);
+		oobs_user_set_crypted_password (user, passwd);
 
 	/* check whether user is allowed to login without password */
 	no_passwd_login_group = get_no_passwd_login_group ();
