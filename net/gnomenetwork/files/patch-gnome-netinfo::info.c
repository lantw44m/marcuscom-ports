--- info.c.orig	Thu Mar 20 15:04:48 2003
+++ info.c	Sat Jun 28 20:45:20 2003
@@ -26,6 +26,10 @@
 #endif
 
 
+#ifdef __FreeBSD__
+#  include <netinet/in.h>
+#endif
+
 #include <sys/socket.h>	/* basic socket definitions */
 #include <arpa/inet.h>	/* inet(3) functions */
 #include <sys/un.h>	/* for Unix domain sockets */
@@ -124,7 +128,7 @@
 	gint flags;
 	gboolean loopback;
 
-	sockfd = socket (AF_INET, SOCK_DGRAM, 0);
+	sockfd = socket (AF_INET, SOCK_STREAM, 0);
 
 	ifc.ifc_len = sizeof (buf);
 	ifc.ifc_req = (struct ifreq *) buf;
@@ -133,13 +137,13 @@
 	for (ptr = buf; ptr < buf + ifc.ifc_len;) {
 		ifr = (struct ifreq *) ptr;
 		len = sizeof (struct sockaddr);
-#ifdef	HAVE_SOCKADDR_SA_LEN
+#if defined(HAVE_SOCKADDR_SA_LEN) || defined(__FreeBSD__)
 		if (ifr->ifr_addr.sa_len > len)
 			len = ifr->ifr_addr.sa_len;	/* length > 16 */
 #endif
 		ptr += sizeof (ifr->ifr_name) + len;	/* for next one in buffer */
 
-		if (strcmp (ifr->ifr_name, nic) != 0) {
+		if (strcmp (ifr->ifr_name, nic) != 0 || ifr->ifr_addr.sa_family != AF_INET) {
 			continue;
 		}
 		
@@ -149,10 +153,10 @@
 			/* Get the IPv4 address */
 			sinptr = (struct sockaddr_in *) &ifr->ifr_addr;
 			inet_ntop (AF_INET, &sinptr->sin_addr, dst, INFO_ADDRSTRLEN);
-			
+		
 			gtk_label_set_text (GTK_LABEL (info->ip_address), dst);
 			bzero (dst, INFO_ADDRSTRLEN);
-			
+		
 			ifrcopy = *ifr;
 			flags = ifrcopy.ifr_flags;
 
@@ -255,7 +259,7 @@
 			break;
 		}
 	}
-	g_free (ifr);
+/*	g_free (ifr);*/
 }
 
 GList *
@@ -269,8 +273,10 @@
 	struct ifreq *ifr;
 	int sockfd, len;
 
-	sockfd = socket (AF_INET, SOCK_DGRAM, 0);
+	sockfd = socket (AF_INET, SOCK_STREAM, 0);
 
+	bzero (&ifc, sizeof (struct ifconf));
+	bzero (&buf, sizeof (buf));
 	ifc.ifc_len = sizeof (buf);
 	ifc.ifc_req = (struct ifreq *) buf;
 
@@ -281,9 +287,11 @@
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
