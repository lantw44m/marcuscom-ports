--- gio/gunixcredentialsmessage.c.orig	2010-08-29 13:05:21.000000000 -0400
+++ gio/gunixcredentialsmessage.c	2010-08-29 13:42:42.000000000 -0400
@@ -46,6 +46,13 @@
 #include <fcntl.h>
 #define G_UNIX_CREDENTIALS_MESSAGE_SUPPORTED 1
 
+#elif defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/un.h>
+#include <unistd.h>
+#include <fcntl.h>
+#define G_UNIX_CREDENTIALS_MESSAGE_SUPPORTED 1
 #else
 /* TODO: please add support for your UNIX flavor */
 #define G_UNIX_CREDENTIALS_MESSAGE_SUPPORTED 0
@@ -79,6 +86,8 @@ g_unix_credentials_message_get_size (GSo
 {
 #ifdef __linux__
   return sizeof (struct ucred);
+#elif defined(__FreeBSD__)
+  return sizeof (struct cmsgcred);
 #else
   return 0;
 #endif
@@ -89,6 +98,8 @@ g_unix_credentials_message_get_level (GS
 {
 #ifdef __linux__
   return SOL_SOCKET;
+#elif defined(__FreeBSD__)
+  return SOL_SOCKET;
 #else
   return 0;
 #endif
@@ -99,6 +110,8 @@ g_unix_credentials_message_get_msg_type 
 {
 #ifdef __linux__
   return SCM_CREDENTIALS;
+#elif defined(__FreeBSD__)
+  return SCM_CREDS;
 #else
   return 0;
 #endif
@@ -140,6 +153,33 @@ g_unix_credentials_message_deserialize (
  out:
     ;
   }
+#elif defined(__FreeBSD__)
+  {
+    GCredentials *credentials;
+    struct cmsgcred *cred;
+
+    if (level != SOL_SOCKET || type != SCM_CREDS)
+      {
+        goto out;
+      }
+    if (size < CMSG_LEN (sizeof *cred))
+      {
+        g_warning ("Expected a struct ucred (%" G_GSIZE_FORMAT " bytes) but "
+                   "got %" G_GSIZE_FORMAT " bytes of data",
+                   CMSG_LEN (sizeof *cred),
+                   size);
+        goto out;
+      }
+
+    cred = data;
+
+    credentials = g_credentials_new ();
+    g_credentials_set_native (credentials, G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED, cred);
+    message = g_unix_credentials_message_new_with_credentials (credentials);
+    g_object_unref (credentials);
+ out:
+    ;
+  }
 #endif
 
   return message;
@@ -155,6 +195,12 @@ g_unix_credentials_message_serialize (GS
           g_credentials_get_native (message->priv->credentials,
                                     G_CREDENTIALS_TYPE_LINUX_UCRED),
           sizeof (struct ucred));
+#elif defined(__FreeBSD__)
+  memcpy (data,
+          g_credentials_get_native (message->priv->credentials,
+                                    G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED),
+          sizeof (struct cmsgcred));
+
 #endif
 }
 
