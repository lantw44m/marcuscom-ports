--- sysdeps/freebsd/netlist.c.orig	Wed Feb 23 01:20:33 2005
+++ sysdeps/freebsd/netlist.c	Wed Feb 23 01:20:44 2005
@@ -50,6 +50,7 @@
 	while(ifs && ifs->if_name) {
 		g_ptr_array_add(devices, g_strdup(ifs->if_name));
 		buf->number++;
+		ifs++;
 	}
 
 	if_freenameindex(ifstart);
