--- sysdeps/freebsd/netload.c.orig	Sat Feb 26 00:43:56 2005
+++ sysdeps/freebsd/netload.c	Sat Feb 26 00:48:46 2005
@@ -40,11 +40,6 @@
 
 static const unsigned long _glibtop_sysdeps_netload =
 (1L << GLIBTOP_NETLOAD_IF_FLAGS) +
-(1L << GLIBTOP_NETLOAD_MTU) +
-#if !defined(__bsdi__)
-(1L << GLIBTOP_NETLOAD_SUBNET) +
-#endif
-(1L << GLIBTOP_NETLOAD_ADDRESS) +
 (1L << GLIBTOP_NETLOAD_PACKETS_IN) +
 (1L << GLIBTOP_NETLOAD_PACKETS_OUT) +
 (1L << GLIBTOP_NETLOAD_PACKETS_TOTAL) +
@@ -56,6 +51,13 @@
 (1L << GLIBTOP_NETLOAD_ERRORS_TOTAL) +
 (1L << GLIBTOP_NETLOAD_COLLISIONS);
 
+static const unsigned _glibtop_sysdeps_netload_data =
+(1L << GLIBTOP_NETLOAD_ADDRESS) +
+#if !defined(__bsdi__)
+(1L << GLIBTOP_NETLOAD_SUBNET) +
+#endif
+(1L << GLIBTOP_NETLOAD_MTU);
+
 /* nlist structure for kernel access */
 static struct nlist nlst [] = {
     { "_ifnet" },
@@ -81,9 +83,9 @@
 {
     struct ifnet ifnet;
     u_long ifnetaddr, ifnetfound, ifaddraddr;
-    struct sockaddr *sa;
+    struct sockaddr *sa = NULL;
     char tname [16];
-    char temp [16];
+    char name [32];
 
     union {
 	struct ifaddr ifa;
@@ -114,13 +116,22 @@
 	    if (kvm_read (server->machine.kd, (u_long) ifnet.if_name,
 			  tname, 16) != 16)
 		    glibtop_error_io_r (server, "kvm_read (if_name)");
-	    snprintf(temp, (15 - strlen(tname)), "%d", ifnet.if_unit);
-	    strcat(tname, temp);
-	    tname [15] = 0;
+	    tname[15] = '\0';
+	    snprintf (name, 32, "%s%d", tname, ifnet.if_unit);
 #else
-	    g_strlcpy (tname, ifnet.if_xname, sizeof tname);
+	    g_strlcpy (name, ifnet.if_xname, sizeof(name));
+#endif
+#if defined(__FreeBSD__) && (__FreeBSD_version >= 300000)
+	    ifnetaddr = (u_long) ifnet.if_link.tqe_next;
+#elif defined(__FreeBSD__) || defined(__bsdi__)
+	    ifnetaddr = (u_long) ifnet.if_next;
+#else
+	    ifnetaddr = (u_long) ifnet.if_list.tqe_next;
 #endif
 
+	    if (strcmp (name, interface) != 0)
+		    continue;
+
 #if defined(__FreeBSD__) && (__FreeBSD_version >= 300000)
 	    ifaddraddr = (u_long) ifnet.if_addrhead.tqh_first;
 #elif defined(__FreeBSD__) || defined(__bsdi__)
@@ -129,6 +140,55 @@
 	    ifaddraddr = (u_long) ifnet.if_addrlist.tqh_first;
 #endif
 	}
+	if (ifnet.if_flags & IFF_UP)
+		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_UP);
+	if (ifnet.if_flags & IFF_BROADCAST)
+		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_BROADCAST);
+	if (ifnet.if_flags & IFF_DEBUG)
+		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_DEBUG);
+	if (ifnet.if_flags & IFF_LOOPBACK)
+		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LOOPBACK);
+	if (ifnet.if_flags & IFF_POINTOPOINT)
+		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_POINTOPOINT);
+	if (ifnet.if_flags & IFF_RUNNING)
+		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_RUNNING);
+	if (ifnet.if_flags & IFF_NOARP)
+		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_NOARP);
+	if (ifnet.if_flags & IFF_PROMISC)
+		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_PROMISC);
+	if (ifnet.if_flags & IFF_ALLMULTI)
+		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_ALLMULTI);
+	if (ifnet.if_flags & IFF_OACTIVE)
+		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_OACTIVE);
+	if (ifnet.if_flags & IFF_SIMPLEX)
+		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_SIMPLEX);
+	if (ifnet.if_flags & IFF_LINK0)
+		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LINK0);
+	if (ifnet.if_flags & IFF_LINK1)
+		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LINK1);
+	if (ifnet.if_flags & IFF_LINK2)
+		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LINK2);
+#ifdef __FreeBSD__
+	if (ifnet.if_flags & IFF_ALTPHYS)
+		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_ALTPHYS);
+#endif
+	if (ifnet.if_flags & IFF_MULTICAST)
+		buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_MULTICAST);
+
+	buf->packets_in = ifnet.if_ipackets;
+	buf->packets_out = ifnet.if_opackets;
+	buf->packets_total = buf->packets_in + buf->packets_out;
+
+	buf->bytes_in = ifnet.if_ibytes;
+	buf->bytes_out = ifnet.if_obytes;
+	buf->bytes_total = buf->bytes_in + buf->bytes_out;
+
+	buf->errors_in = ifnet.if_ierrors;
+	buf->errors_out = ifnet.if_oerrors;
+	buf->errors_total = buf->errors_in + buf->errors_out;
+
+	buf->collisions = ifnet.if_collisions;
+	buf->flags = _glibtop_sysdeps_netload;
 
 	if (ifaddraddr) {
 	    if ((kvm_read (server->machine.kd, ifaddraddr, &ifaddr,
@@ -137,86 +197,22 @@
 
 #define CP(x) ((char *)(x))
 	    cp = (CP(ifaddr.ifa.ifa_addr) - CP(ifaddraddr)) +
-		CP(&ifaddr); sa = (struct sockaddr *)cp;
+		CP(&ifaddr);
+	    sa = (struct sockaddr *)cp;
 
-	    if (!strcmp (interface, tname) && (sa->sa_family == AF_INET)) {
+	    if (sa->sa_family == AF_INET) {
 		sin = (struct sockaddr_in *)sa;
-
-		if (ifnet.if_flags & IFF_UP)
-			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_UP);
-		if (ifnet.if_flags & IFF_BROADCAST)
-			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_BROADCAST);
-		if (ifnet.if_flags & IFF_DEBUG)
-			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_DEBUG);
-		if (ifnet.if_flags & IFF_LOOPBACK)
-			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LOOPBACK);
-		if (ifnet.if_flags & IFF_POINTOPOINT)
-			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_POINTOPOINT);
-		if (ifnet.if_flags & IFF_RUNNING)
-			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_RUNNING);
-		if (ifnet.if_flags & IFF_NOARP)
-			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_NOARP);
-		if (ifnet.if_flags & IFF_PROMISC)
-			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_PROMISC);
-		if (ifnet.if_flags & IFF_ALLMULTI)
-			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_ALLMULTI);
-		if (ifnet.if_flags & IFF_OACTIVE)
-			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_OACTIVE);
-		if (ifnet.if_flags & IFF_SIMPLEX)
-			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_SIMPLEX);
-		if (ifnet.if_flags & IFF_LINK0)
-			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LINK0);
-		if (ifnet.if_flags & IFF_LINK1)
-			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LINK1);
-		if (ifnet.if_flags & IFF_LINK2)
-			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_LINK2);
-#ifdef __FreeBSD__
-		if (ifnet.if_flags & IFF_ALTPHYS)
-			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_ALTPHYS);
-#endif
-		if (ifnet.if_flags & IFF_MULTICAST)
-			buf->if_flags |= (1L << GLIBTOP_IF_FLAGS_MULTICAST);
-
 #if !defined(__bsdi__)
 		/* Commenting out to "fix" #13345. */
 		buf->subnet = htonl (ifaddr.in.ia_subnet);
 #endif
 		buf->address = sin->sin_addr.s_addr;
-
 		buf->mtu = ifnet.if_mtu;
 
-		buf->packets_in = ifnet.if_ipackets;
-		buf->packets_out = ifnet.if_opackets;
-		buf->packets_total = buf->packets_in + buf->packets_out;
-
-		buf->bytes_in = ifnet.if_ibytes;
-		buf->bytes_out = ifnet.if_obytes;
-		buf->bytes_total = buf->bytes_in + buf->bytes_out;
-
-		buf->errors_in = ifnet.if_ierrors;
-		buf->errors_out = ifnet.if_oerrors;
-		buf->errors_total = buf->errors_in + buf->errors_out;
-
-		buf->collisions = ifnet.if_collisions;
-		buf->flags = _glibtop_sysdeps_netload;
-		return;
-	    }
+		buf->flags |= _glibtop_sysdeps_netload_data;
 
-#if defined(__FreeBSD__) && (__FreeBSD_version >= 300000)
-	    ifaddraddr = (u_long)ifaddr.ifa.ifa_link.tqe_next;
-#elif defined(__FreeBSD__) || defined(__bsdi__)
-	    ifaddraddr = (u_long)ifaddr.ifa.ifa_next;
-#else
-	    ifaddraddr = (u_long)ifaddr.ifa.ifa_list.tqe_next;
-#endif
+	    }
 	}
-
-#if defined(__FreeBSD__) && (__FreeBSD_version >= 300000)
-	ifnetaddr = (u_long) ifnet.if_link.tqe_next;
-#elif defined(__FreeBSD__) || defined(__bsdi__)
-	ifnetaddr = (u_long) ifnet.if_next;
-#else
-	ifnetaddr = (u_long) ifnet.if_list.tqe_next;
-#endif
+	return;
     }
 }
