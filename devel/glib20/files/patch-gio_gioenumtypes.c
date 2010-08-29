--- gio/gioenumtypes.c.orig	2010-08-29 12:45:26.000000000 -0400
+++ gio/gioenumtypes.c	2010-08-29 12:45:58.000000000 -0400
@@ -1130,6 +1130,7 @@ g_credentials_type_get_type (void)
       static const GEnumValue values[] = {
         { G_CREDENTIALS_TYPE_INVALID, "G_CREDENTIALS_TYPE_INVALID", "invalid" },
         { G_CREDENTIALS_TYPE_LINUX_UCRED, "G_CREDENTIALS_TYPE_LINUX_UCRED", "linux-ucred" },
+        { G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED, "G_CREDENTIALS_TYPE_FREEBSD_CMSGCRED", "freebsd-cmsgcred" },
         { 0, NULL, NULL }
       };
       GType g_define_type_id =
