--- src/users/user-settings.c.orig	2009-11-30 17:40:27.000000000 -0500
+++ src/users/user-settings.c	2010-01-05 18:51:40.000000000 -0500
@@ -1228,12 +1228,12 @@ on_edit_user_passwd (GtkButton *button, 
 			                                    "changed"));
 
 		if (passwd_changed)
-			oobs_user_set_password (user,
+			oobs_user_set_crypted_password (user,
 			                        gtk_entry_get_text (GTK_ENTRY (passwd_entry)));
 	} else {
 		passwd_entry = gst_dialog_get_widget (tool->main_dialog,
 		                                      "user_settings_random_passwd");
-		oobs_user_set_password (user,
+		oobs_user_set_crypted_password (user,
 		                        gtk_entry_get_text (GTK_ENTRY (passwd_entry)));
 	}
 
