--- src/user.c.orig	2011-03-27 20:27:40.000000000 +0200
+++ src/user.c	2011-03-27 20:34:18.000000000 +0200
@@ -29,7 +29,11 @@
 #include <sys/wait.h>
 #include <unistd.h>
 #include <grp.h>
+#ifdef __FreeBSD__
+#include <pwd.h>
+#else
 #include <shadow.h>
+#endif
 
 #include <glib.h>
 #include <glib/gi18n.h>
@@ -447,7 +451,11 @@ void
 user_local_update_from_pwent (User          *user,
                               struct passwd *pwent)
 {
+#ifdef __FreeBSD__
+        struct passwd *spent;
+#else
         struct spwd *spent;
+#endif
         gchar *real_name;
         gboolean changed;
         const gchar *passwd;
@@ -538,9 +546,15 @@ user_local_update_from_pwent (User      
         }
 
         passwd = pwent->pw_passwd;
+#ifdef __FreeBSD__
+        spent = getpwnam (pwent->pw_name);
+        if (spent)
+                passwd = spent->pw_passwd;
+#else
         spent = getspnam (pwent->pw_name);
         if (spent)
                 passwd = spent->sp_pwdp;
+#endif
 
         if (passwd && passwd[0] == '!') {
                 locked = TRUE;
@@ -562,11 +576,13 @@ user_local_update_from_pwent (User      
                 mode = PASSWORD_MODE_REGULAR;
         }
 
+#ifndef __FreeBSD__
         if (spent) {
                 if (spent->sp_lstchg == 0) {
                         mode = PASSWORD_MODE_SET_AT_LOGIN;
                 }
         }
+#endif
 
         if (user->password_mode != mode) {
                 user->password_mode = mode;
