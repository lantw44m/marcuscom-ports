--- libgnetwork/gnetwork-udp-datagram.c.orig	Thu Dec 11 23:28:22 2003
+++ libgnetwork/gnetwork-udp-datagram.c	Thu Dec 11 23:31:01 2003
@@ -40,6 +40,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <unistd.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/types.h>
 #include <sys/socket.h>
@@ -208,8 +209,13 @@
       sa = g_malloc0 (sa_size);
 
       errno = 0;
+#ifdef MSG_NOSIGNAL
       bytes_done = recvfrom (udp->_priv->sockfd, buffer, udp->_priv->buffer_size, MSG_NOSIGNAL,
 			     sa, &sa_size);
+#else
+      bytes_done = recvfrom (udp->_priv->sockfd, buffer, udp->_priv->buffer_size, 0,
+	      		    sa, &sa_size);
+#endif
       en = errno;
 
       target->hostname = NULL;
@@ -281,8 +287,13 @@
 						 &sa_size);
 
 	  errno = 0;
+#ifdef MSG_NOSIGNAL
 	  bytes_done = sendto (udp->_priv->sockfd, item->data, item->length, MSG_NOSIGNAL, sa,
 			       sa_size);
+#else
+	  bytes_done = sendto (udp->_priv->sockfd, item->data, item->length, 0, sa,
+		  	       sa_size);
+#endif
 	  en = errno;
 	  g_free (sa);
 
