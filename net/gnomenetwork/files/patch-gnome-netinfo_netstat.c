--- gnome-netinfo/netstat.c.orig	Mon Sep  1 02:05:22 2003
+++ gnome-netinfo/netstat.c	Mon Sep  1 02:31:00 2003
@@ -109,7 +109,11 @@
 	}
 	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (netinfo->protocol))) {
 		/* Only works for Solaris */
+#ifdef __FreeBSD__
+	    	option = g_strdup ("-a -f inet -ln");
+#else
 		option = g_strdup ("-A inet -ln");
+#endif
 	}
 	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (netinfo->multicast))) {
 		/* It works for Solaris and Linux */
@@ -335,11 +339,27 @@
 strip_protocol_line (gchar * line, netstat_protocol_data *data)
 {
 	gint count = 0;
+#ifdef __FreeBSD__
+	gint a1, a2, a3, a4;
+	gchar s9[30];
+#else
 	gchar s6[30], s7[30];
+#endif
 	gint n2, n3;
 
 	line = g_strdelimit (line, ":", ' ');
 
+#ifdef __FreeBSD__
+	count = sscanf (line, NETSTAT_PROTOCOL_FORMAT,
+			&(data)->protocol, &n2, &n3,
+			&a1, &a2, &a3, &a4, &(data)->port_src,
+			s9, &(data)->state);
+	snprintf (&(data)->ip_src, 30, "%d.%d.%d.%d", a1, a2, a3, a4);
+
+	if (count == 9) {
+	    bzero (&(data)->state, 30);
+	}
+#else
 	count = sscanf (line, NETSTAT_PROTOCOL_FORMAT,
 			&(data)->protocol, &n2, &n3,
 			&(data)->ip_src, &(data)->port_src, 
@@ -348,6 +368,7 @@
 	if (count == 7) {
 		bzero (&(data)->state, 30);
 	}
+#endif
 	
 	return count;
 }
@@ -477,12 +498,23 @@
 	gint count = 0;
 	gchar flags[30];
 	gint ref, use;
+#ifdef __FreeBSD__
+	gint expire;
+#endif
 
+#ifdef __FreeBSD__
+	count = sscanf (line, NETSTAT_ROUTE_FORMAT,
+			&(data)->destination,
+			&(data)->gateway, flags,
+			&ref, &use, &(data)->iface,
+			&expire);
+#else
 	count = sscanf (line, NETSTAT_ROUTE_FORMAT,
 			&(data)->destination,
 			&(data)->gateway, &(data)->netmask, 
 			flags, &(data)->metric, &ref, &use, 
 			&(data)->iface);
+#endif
 	
 	return count;
 }
