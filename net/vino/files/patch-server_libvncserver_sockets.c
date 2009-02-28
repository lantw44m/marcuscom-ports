--- server/libvncserver/sockets.c.orig	2009-02-13 08:11:38.000000000 -0500
+++ server/libvncserver/sockets.c	2009-02-27 20:24:02.000000000 -0500
@@ -580,6 +580,7 @@ ListenOnTCPPort(rfbScreenInfoPtr rfbScre
   {
 #ifdef ENABLE_IPV6
     struct sockaddr_in6 s6;
+    int off = 0;
 
     memset(&s6, 0, sizeof(s6));
     s6.sin6_family = AF_INET6;
@@ -587,6 +588,9 @@ ListenOnTCPPort(rfbScreenInfoPtr rfbScre
     s6.sin6_addr   = in6addr_any;
 
     sock = NewSocketListenTCP ((struct sockaddr*)&s6, sizeof(s6));
+#ifdef IPV6_V6ONLY
+    setsockopt(sock, IPPROTO_IPV6, IPV6_V6ONLY, (void *)&off, sizeof(off));
+#endif
     rfbLog("Listening IPv{4,6}://*:%d\n", port);
 #endif
     if(sock < 0) {
