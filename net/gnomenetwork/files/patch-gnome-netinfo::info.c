--- gnome-netinfo/info.c.orig	Thu Jul 24 18:10:39 2003
+++ gnome-netinfo/info.c	Mon Sep  1 00:36:32 2003
@@ -26,6 +26,7 @@
 #endif
 
 
+#include <netinet/in.h>
 #include <sys/socket.h>	/* basic socket definitions */
 #include <arpa/inet.h>	/* inet(3) functions */
 #include <sys/un.h>	/* for Unix domain sockets */
@@ -180,7 +181,7 @@
 	gboolean loopback;
 	mii_data_result data;
 		
-	sockfd = socket (AF_INET, SOCK_DGRAM, 0);
+	sockfd = socket (AF_INET, SOCK_STREAM, 0);
 
 	ifc.ifc_len = sizeof (buf);
 	ifc.ifc_req = (struct ifreq *) buf;
@@ -189,7 +190,7 @@
 	for (ptr = buf; ptr < buf + ifc.ifc_len;) {
 		ifr = (struct ifreq *) ptr;
 		len = sizeof (struct sockaddr);
-#ifdef	HAVE_SOCKADDR_SA_LEN
+#if	defined(HAVE_SOCKADDR_SA_LEN) || defined(__FreeBSD__)
 		if (ifr->ifr_addr.sa_len > len)
 			len = ifr->ifr_addr.sa_len;	/* length > 16 */
 #endif
@@ -322,7 +323,6 @@
 			break;
 		}
 	}
-	g_free (ifr);
 }
 
 GList *
@@ -336,8 +336,10 @@
 	struct ifreq *ifr;
 	int sockfd, len;
 
-	sockfd = socket (AF_INET, SOCK_DGRAM, 0);
+	sockfd = socket (AF_INET, SOCK_STREAM, 0);
 
+	bzero (&ifc, sizeof (struct ifconf));
+	bzero (&buf, sizeof (buf));
 	ifc.ifc_len = sizeof (buf);
 	ifc.ifc_req = (struct ifreq *) buf;
 
@@ -348,9 +350,11 @@
 		len = sizeof (struct sockaddr);
 
 		iface = g_strdup (ifr->ifr_name);
-		items = g_list_append (items, iface);
+		if (g_list_find_custom (items, iface, (GCompareFunc) g_ascii_strcasecmp) == NULL) {
+			items = g_list_append (items, iface);
+		}
 
-#ifdef	HAVE_SOCKADDR_SA_LEN
+#if defined(HAVE_SOCKADDR_SA_LEN) || defined(__FreeBSD__)
 		if (ifr->ifr_addr.sa_len > len)
 			len = ifr->ifr_addr.sa_len;	/* length > 16 */
 #endif
