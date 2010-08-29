--- gio/gcredentials.c.orig	2010-08-29 12:29:02.000000000 -0400
+++ gio/gcredentials.c	2010-08-29 13:46:08.000000000 -0400
@@ -22,6 +22,10 @@
 
 #include "config.h"
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/socket.h>
+#endif
 #include <stdlib.h>
 
 #include <gobject/gvaluecollector.h>
@@ -55,6 +59,9 @@
  * <citerefentry><refentrytitle>unix</refentrytitle><manvolnum>7</manvolnum></citerefentry>
  * man page for details. This corresponds to
  * %G_CREDENTIALS_TYPE_LINUX_UCRED.
+ *
+ * On FreeBSD, the native credential type is a <type>struct cmsgcred</type>.
+ * This corresponds to %G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED.
  */
 
 /**
@@ -72,6 +79,8 @@ struct _GCredentials
 
 #ifdef __linux__
   struct ucred native;
+#elif defined(__FreeBSD__)
+  struct cmsgcred native;
 #else
 #ifdef __GNUC__
 #warning Please add GCredentials support for your OS
@@ -120,6 +129,11 @@ g_credentials_init (GCredentials *creden
   credentials->native.pid = getpid ();
   credentials->native.uid = geteuid ();
   credentials->native.gid = getegid ();
+#elif defined(__FreeBSD__)
+  memset (&credentials->native, 0, sizeof (struct cmsgcred));
+  credentials->native.cmcred_pid  = getpid ();
+  credentials->native.cmcred_euid = geteuid ();
+  credentials->native.cmcred_gid  = getegid ();
 #endif
 }
 
@@ -173,6 +187,14 @@ g_credentials_to_string (GCredentials *c
     g_string_append_printf (ret, "gid=%" G_GINT64_FORMAT ",", (gint64) credentials->native.gid);
   if (ret->str[ret->len - 1] == ',')
     ret->str[ret->len - 1] = '\0';
+#elif defined(__FreeBSD__)
+  g_string_append (ret, "freebsd-cmsgcred:");
+  if (credentials->native.cmcred_pid != -1)
+    g_string_append_printf (ret, "pid=%" G_GINT64_FORMAT ",", (gint64) credentials->native.cmcred_pid);
+  if (credentials->native.cmcred_euid != -1)
+    g_string_append_printf (ret, "uid=%" G_GINT64_FORMAT ",", (gint64) credentials->native.cmcred_euid);
+  if (credentials->native.cmcred_gid != -1)
+    g_string_append_printf (ret, "gid=%" G_GINT64_FORMAT ",", (gint64) credentials->native.cmcred_gid);
 #else
   g_string_append (ret, "unknown");
 #endif
@@ -213,6 +235,9 @@ g_credentials_is_same_user (GCredentials
 #ifdef __linux__
   if (credentials->native.uid == other_credentials->native.uid)
     ret = TRUE;
+#elif defined(__FreeBSD__)
+  if (credentials->native.cmcred_euid == other_credentials->native.cmcred_euid)
+    ret = TRUE;
 #else
   g_set_error_literal (error,
                        G_IO_ERROR,
@@ -263,6 +288,17 @@ g_credentials_get_native (GCredentials  
     {
       ret = &credentials->native;
     }
+#elif defined(__FreeBSD__)
+  if (native_type != G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED)
+    {
+      g_waring ("g_credentials_get_native: Trying to get credentials of type %d but only "
+		 "G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED is supported.",
+		 native_type);
+    }
+  else
+    {
+      ret = &credentials->native;
+    }
 #else
   g_warning ("g_credentials_get_native: Trying to get credentials but GLib has no support "
              "for the native credentials type. Please add support.");
@@ -302,6 +338,17 @@ g_credentials_set_native (GCredentials  
     {
       memcpy (&credentials->native, native, sizeof (struct ucred));
     }
+#elif defined(__FreeBSD__)
+  if (native_type != G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED)
+    {
+      g_warning ("g_credentials_set_native: Trying to set credentials of type %d "
+		  "but only G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED is supported.",
+		  native_type);
+    }
+  else
+    {
+      memcpy (&credentials->native, native, sizeof (struct cmsgcred));
+    }
 #else
   g_warning ("g_credentials_set_native: Trying to set credentials but GLib has no support "
              "for the native credentials type. Please add support.");
@@ -338,6 +385,8 @@ g_credentials_get_unix_user (GCredential
 
 #ifdef __linux__
   ret = credentials->native.uid;
+#elif defined(__FreeBSD__)
+  ret = credentials->native.cmcred_euid;
 #else
   ret = -1;
   g_set_error_literal (error,
@@ -381,6 +430,9 @@ g_credentials_set_unix_user (GCredential
 #ifdef __linux__
   credentials->native.uid = uid;
   ret = TRUE;
+#elif defined(__FreeBSD__)
+  credentials->native.cmcred_euid = uid;
+  ret = TRUE;
 #else
   g_set_error_literal (error,
                        G_IO_ERROR,
