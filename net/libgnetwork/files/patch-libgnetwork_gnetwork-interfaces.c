--- libgnetwork/gnetwork-interfaces.c.orig	Thu Dec 11 21:27:32 2003
+++ libgnetwork/gnetwork-interfaces.c	Thu Dec 11 23:33:27 2003
@@ -34,11 +34,16 @@
 #include <unistd.h>
 
 /* Interfaces & Addresses */
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <net/if.h>
+#ifdef __linux__
 #include <netpacket/packet.h>
 #include <netinet/ether.h>
+#else
+#include <net/ethernet.h>
+#endif
 #include <ifaddrs.h>
 #include <arpa/inet.h>
 
@@ -72,7 +77,7 @@
   gchar *hw_address;
   gchar *hw_broadcast_or_destination;
 
-  GNetworkInterfaceFlags flags:15;
+  GNetworkInterfaceFlags flags:16;
   GNetworkProtocols protocols:3;
 };
 
@@ -126,6 +131,7 @@
       _gnetwork_ip_address_set_from_sockaddr (&(info->ip6_netmask), data->ifa_netmask);
       _gnetwork_ip_address_set_from_sockaddr (&(info->ip6_destination), data->ifa_dstaddr);
       break;
+#ifdef AF_PACKET
     case AF_PACKET:
       info->protocols |= GNETWORK_PROTOCOL_PACKET;
 
@@ -134,6 +140,7 @@
       info->hw_address = _gnetwork_sockaddr_get_address (data->ifa_addr);
       info->hw_broadcast_or_destination = _gnetwork_sockaddr_get_address (data->ifa_dstaddr);
       break;
+#endif
     }
 }
 
