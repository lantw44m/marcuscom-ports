--- sysdeps/freebsd/netlist.c.orig	Sun Dec  5 07:01:43 2004
+++ sysdeps/freebsd/netlist.c	Sat Feb 26 00:13:28 2005
@@ -43,6 +43,10 @@
 	struct if_nameindex *ifstart, *ifs;
 	GPtrArray *devices;
 
+	glibtop_init_s (&server, GLIBTOP_SYSDEPS_NETLIST, 0);
+
+	memset (buf, 0, sizeof (glibtop_netlist));
+
 	ifs = ifstart = if_nameindex();
 
 	devices = g_ptr_array_new();
@@ -50,6 +54,7 @@
 	while(ifs && ifs->if_name) {
 		g_ptr_array_add(devices, g_strdup(ifs->if_name));
 		buf->number++;
+		ifs++;
 	}
 
 	if_freenameindex(ifstart);
