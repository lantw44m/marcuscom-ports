--- modules/http-method.c.orig	Mon Aug 11 12:17:18 2003
+++ modules/http-method.c	Mon Aug 11 12:19:48 2003
@@ -198,8 +198,12 @@
 #ifdef ENABLE_IPV6
 	struct in6_addr addr6;
 	struct in6_addr mask6;
+#ifdef __FreeBSD__
+#define s6_addr32 __u6_addr.__u6_addr32
+#endif
 #endif
 } ProxyHostAddr;
+
 
 typedef struct {
 	GnomeVFSSocketBuffer *socket_buffer;
