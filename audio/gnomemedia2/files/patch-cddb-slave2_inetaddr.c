--- cddb-slave2/inetaddr.c.orig	Sat Mar 12 02:38:12 2005
+++ cddb-slave2/inetaddr.c	Sat Mar 12 02:39:15 2005
@@ -1908,6 +1908,9 @@ gnet_inetaddr_get_interface_to (const GI
   int sockfd;
 #ifdef ENABLE_IPV6
   struct sockaddr_in6 myaddr6;
+#define SS_LEN ss_len
+#else
+#define SS_LEN sa_len
 #endif
   struct sockaddr_in myaddr;
   socklen_t len;
@@ -1927,7 +1930,7 @@ gnet_inetaddr_get_interface_to (const GI
 	return NULL;
       }
 
-      if (connect (sockfd, (struct sockaddr *)&(addr->sa), sizeof (addr->sa)) == -1)
+      if (connect (sockfd, (struct sockaddr *)&(addr->sa), addr->sa.SS_LEN) == -1)
 	{
 	  GNET_CLOSE_SOCKET (sockfd);
 	  g_free (iface);
@@ -1953,7 +1956,7 @@ gnet_inetaddr_get_interface_to (const GI
       return NULL;
     }
 
-    if (connect (sockfd, (struct sockaddr *)&addr->sa, sizeof(addr->sa)) == -1)
+    if (connect (sockfd, (struct sockaddr *)&addr->sa, addr->sa.SS_LEN) == -1)
       {
 	GNET_CLOSE_SOCKET(sockfd);
 	g_free (iface);
