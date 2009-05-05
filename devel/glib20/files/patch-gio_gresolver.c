--- gio/gresolver.c.orig	2009-05-05 17:08:34.000000000 -0400
+++ gio/gresolver.c	2009-05-05 17:08:47.000000000 -0400
@@ -636,7 +636,9 @@ g_resolver_error_from_addrinfo_error (gi
   switch (err)
     {
     case EAI_FAIL:
+#ifdef EAI_NODATA
     case EAI_NODATA:
+#endif
     case EAI_NONAME:
       return G_RESOLVER_ERROR_NOT_FOUND;
 
