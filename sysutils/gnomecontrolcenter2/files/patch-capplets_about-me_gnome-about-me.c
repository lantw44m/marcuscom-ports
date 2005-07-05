--- capplets/about-me/gnome-about-me.c.orig	Tue Jul  5 14:17:38 2005
+++ capplets/about-me/gnome-about-me.c	Tue Jul  5 14:20:06 2005
@@ -260,12 +260,10 @@ about_me_focus_out (GtkWidget *widget, G
 static char *
 get_user_login (void)
 {
-	char buf[LINE_MAX * 4];
-	struct passwd pwd, *err;
+	struct passwd *pwd;
 
-	int i;
-	i = getpwuid_r(getuid(), &pwd, buf, sizeof(buf), &err);
-	return ((i == 0) && (err == &pwd)) ? g_strdup(pwd.pw_name) : NULL;
+	pwd = getpwuid(getuid());
+	return (pwd != NULL) ? g_strdup(pwd->pw_name) : NULL;
 }
 
 /*
@@ -655,6 +653,7 @@ about_me_setup_dialog (void)
 	struct passwd *pwent;
 	char *user = NULL;
 	gchar *str;
+	gchar **tok;
 
 	me = g_new0 (GnomeAboutMe, 1);
 
@@ -711,7 +710,6 @@ about_me_setup_dialog (void)
 				_("Unknown login ID, the user database might be corrupted"));
 		return ;
 	}
-	gchar **tok;
 	tok = g_strsplit (pwent->pw_gecos, ",", 0);
 
 	/************************************************/
