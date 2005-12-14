--- libgnomevfs/gnome-vfs-address.c.orig	Tue Dec 13 21:41:32 2005
+++ libgnomevfs/gnome-vfs-address.c	Wed Dec 14 00:15:32 2005
@@ -32,6 +32,7 @@
 #include <sys/types.h>
 
 #ifndef G_OS_WIN32
+#include <sys/socket.h>
 #include <sys/select.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
@@ -388,8 +389,8 @@ static gboolean
 v6_v6_equal (const struct sockaddr_in6 *a,
 	     const struct sockaddr_in6 *b)
 {
-	return IN6_ARE_ADDR_EQUAL (a->sin6_addr.s6_addr,
-				   b->sin6_addr.s6_addr);
+	return IN6_ARE_ADDR_EQUAL (&a->sin6_addr,
+				   &b->sin6_addr);
 }
 
 static gboolean
