--- libgnetwork/gnetwork-utils.c.orig	Thu Dec 11 23:31:20 2003
+++ libgnetwork/gnetwork-utils.c	Thu Dec 11 23:32:55 2003
@@ -30,8 +30,13 @@
 #include <errno.h>
 
 #include <net/if.h>
+#ifdef __linux__
 #include <netpacket/packet.h>
 #include <netinet/ether.h>
+#else
+#include <net/ethernet.h>
+#endif
+#include <netinet/in.h>
 #include <arpa/inet.h>
 
 #include <unistd.h>
@@ -269,6 +274,7 @@
 	  inet_ntop (sock->sa_family, &(((struct sockaddr_in6 *) sock)->sin6_addr), address,
 		     INET_ADDRESS_SIZE);
 	  break;
+#ifdef AF_PACKET
 	case AF_PACKET:
 	  switch (((struct sockaddr_ll *) sock)->sll_halen)
 	    {
@@ -285,6 +291,7 @@
 	      break;
 	    }
 	  break;
+#endif
 	}
 
       return (address[0] != '\0' ? g_strdup (address) : NULL);
@@ -335,9 +342,11 @@
 	case AF_INET6:
 	  retval = GNETWORK_PROTOCOL_IPv6;
 	  break;
+#ifdef AF_PACKET
 	case AF_PACKET:
 	  retval = GNETWORK_PROTOCOL_PACKET;
 	  break;
+#endif
 	default:
 	  break;
 	}
