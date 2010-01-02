--- gui/simple-chooser/gdm-host-chooser-widget.c.orig	2009-12-21 17:36:30.000000000 +0100
+++ gui/simple-chooser/gdm-host-chooser-widget.c	2009-12-26 23:31:52.000000000 +0100
@@ -443,7 +443,7 @@ find_broadcast_addresses (GdmHostChooser
                         /* paranoia */
                         ifreq.ifr_name[sizeof (ifreq.ifr_name) - 1] = '\0';
 
-                        if (ioctl (sock, SIOCGIFFLAGS, &ifreq) < 0) {
+                        if ((ioctl (sock, SIOCGIFFLAGS, &ifreq) < 0) && (errno != ENXIO)) {
                                 g_warning ("Could not get SIOCGIFFLAGS for %s", ifr[i].ifr_name);
                         }
 
@@ -543,6 +543,8 @@ xdmcp_init (GdmHostChooserWidget *widget
 #ifdef ENABLE_IPV6
         widget->priv->socket_fd = socket (AF_INET6, SOCK_DGRAM, 0);
         if (widget->priv->socket_fd != -1) {
+                int off = 0;
+                setsockopt(widget->priv->socket_fd, IPPROTO_IPV6, IPV6_V6ONLY, (void *)&off, sizeof (off));
                 widget->priv->have_ipv6 = TRUE;
         }
 #endif
