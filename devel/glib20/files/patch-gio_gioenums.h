--- gio/gioenums.h.orig	2010-08-29 12:43:20.000000000 -0400
+++ gio/gioenums.h	2010-08-29 12:44:12.000000000 -0400
@@ -1173,6 +1173,7 @@ typedef enum
  * GCredentialsType:
  * @G_CREDENTIALS_TYPE_INVALID: Indicates an invalid native credential type.
  * @G_CREDENTIALS_TYPE_LINUX_UCRED: The native credentials type is a <type>struct ucred</type>.
+ * @G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED: The native credentials type is a <type>struct cmsgcred</type>.
  *
  * Enumeration describing different kinds of native credential types.
  *
@@ -1181,7 +1182,8 @@ typedef enum
 typedef enum
 {
   G_CREDENTIALS_TYPE_INVALID,
-  G_CREDENTIALS_TYPE_LINUX_UCRED
+  G_CREDENTIALS_TYPE_LINUX_UCRED,
+  G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED
 } GCredentialsType;
 
 /**
