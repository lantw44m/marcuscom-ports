--- sysdeps/freebsd/swap.c.orig	Tue Dec  2 14:57:38 2003
+++ sysdeps/freebsd/swap.c	Tue Dec  2 15:05:38 2003
@@ -267,7 +267,7 @@
 	/* List of swap devices and sizes. */
 
 	sw_size = nswdev * sizeof (*sw);
-	sw = g_malloc (server, sw_size);
+	sw = g_malloc (sw_size);
 
 	if (kvm_read (server->machine.kd, ptr, sw, sw_size) != (ssize_t)sw_size) {
 		glibtop_warn_io_r (server, "kvm_read (*swdevt)");
@@ -367,8 +367,8 @@
 
 	buf->flags = _glibtop_sysdeps_swap;
 
-	buf->used = kvmsw[nswdev].ksw_used;
-	buf->total = kvmsw[nswdev].ksw_total;
+	buf->used = kvmsw[nswdev].ksw_used * getpagesize ();
+	buf->total = kvmsw[nswdev].ksw_total * getpagesize ();
 
 	buf->free = buf->total - buf->used;
 
@@ -399,7 +399,7 @@
 		return;
 	}
 
-	swaplist = g_malloc (server, nswap * sizeof (struct swapent));
+	swaplist = g_malloc (nswap * sizeof (struct swapent));
 
 	if (swapctl (SWAP_STATS, swaplist, nswap) != nswap) {
 		glibtop_warn_io_r (server, "swapctl (SWAP_STATS)");
