--- src/user.c.orig	2011-08-16 14:53:31.000000000 +0200
+++ src/user.c	2011-10-05 00:20:33.000000000 +0200
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
@@ -464,7 +468,11 @@ void
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
@@ -555,9 +563,15 @@ user_local_update_from_pwent (User      
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
@@ -579,11 +593,13 @@ user_local_update_from_pwent (User      
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
@@ -1370,6 +1386,7 @@ user_change_icon_file_authorized_cb (Dae
         GFile *file;
         GFileInfo *info;
         guint32 mode;
+        GFileType type;
         guint64 size;
 
         filename = g_strdup (data);
@@ -1400,14 +1417,23 @@ user_change_icon_file_authorized_cb (Dae
 
         file = g_file_new_for_path (filename);
         info = g_file_query_info (file, G_FILE_ATTRIBUTE_UNIX_MODE ","
+                                        G_FILE_ATTRIBUTE_STANDARD_TYPE ","
                                         G_FILE_ATTRIBUTE_STANDARD_SIZE,
                                   0, NULL, NULL);
         mode = g_file_info_get_attribute_uint32 (info, G_FILE_ATTRIBUTE_UNIX_MODE);
+        type = g_file_info_get_file_type (info);
         size = g_file_info_get_attribute_uint64 (info, G_FILE_ATTRIBUTE_STANDARD_SIZE);
 
         g_object_unref (info);
         g_object_unref (file);
 
+        if (type != G_FILE_TYPE_REGULAR) {
+                g_debug ("not a regular file\n");
+                throw_error (context, ERROR_FAILED, "file '%s' is not a regular file", filename);
+                g_free (filename);
+                return;
+        }
+
         if (size > 1048576) {
                 g_debug ("file too large\n");
                 /* 1MB ought to be enough for everybody */
