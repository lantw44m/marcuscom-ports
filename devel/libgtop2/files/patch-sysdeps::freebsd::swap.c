--- sysdeps/freebsd/swap.c.orig	Tue Oct 21 18:54:25 2003
+++ sysdeps/freebsd/swap.c	Sun Feb 15 15:46:20 2004
@@ -267,7 +267,7 @@
 	/* List of swap devices and sizes. */
 
 	sw_size = nswdev * sizeof (*sw);
-	sw = g_malloc (server, sw_size);
+	sw = g_malloc (sw_size);
 
 	if (kvm_read (server->machine.kd, ptr, sw, sw_size) != (ssize_t)sw_size) {
 		glibtop_warn_io_r (server, "kvm_read (*swdevt)");
@@ -399,7 +399,7 @@
 		return;
 	}
 
-	swaplist = g_malloc (server, nswap * sizeof (struct swapent));
+	swaplist = g_malloc (nswap * sizeof (struct swapent));
 
 	if (swapctl (SWAP_STATS, swaplist, nswap) != nswap) {
 		glibtop_warn_io_r (server, "swapctl (SWAP_STATS)");
