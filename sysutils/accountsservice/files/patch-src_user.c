--- src/user.c.orig	2011-10-16 20:25:22.000000000 +0200
+++ src/user.c	2011-10-16 20:24:29.000000000 +0200
@@ -29,7 +29,9 @@
 #include <sys/wait.h>
 #include <unistd.h>
 #include <grp.h>
+#ifdef HAVE_SHADOW_H
 #include <shadow.h>
+#endif
 
 #include <glib.h>
 #include <glib/gi18n.h>
@@ -464,7 +466,9 @@ void
 user_local_update_from_pwent (User          *user,
                               struct passwd *pwent)
 {
+#ifdef HAVE_SHADOW_H
         struct spwd *spent;
+#endif
         gchar *real_name;
         gboolean changed;
         const gchar *passwd;
@@ -555,9 +559,11 @@ user_local_update_from_pwent (User      
         }
 
         passwd = pwent->pw_passwd;
+#ifdef HAVE_SHADOW_H
         spent = getspnam (pwent->pw_name);
         if (spent)
                 passwd = spent->sp_pwdp;
+#endif
 
         if (passwd && passwd[0] == '!') {
                 locked = TRUE;
@@ -579,11 +585,13 @@ user_local_update_from_pwent (User      
                 mode = PASSWORD_MODE_REGULAR;
         }
 
+#ifdef HAVE_SHADOW_H
         if (spent) {
                 if (spent->sp_lstchg == 0) {
                         mode = PASSWORD_MODE_SET_AT_LOGIN;
                 }
         }
+#endif
 
         if (user->password_mode != mode) {
                 user->password_mode = mode;
