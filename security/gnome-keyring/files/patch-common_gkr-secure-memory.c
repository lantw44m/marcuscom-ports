--- common/gkr-secure-memory.c.orig	Mon Jun 18 21:08:53 2007
+++ common/gkr-secure-memory.c	Mon Jun 18 21:09:11 2007
@@ -409,7 +409,7 @@ get_locked_pages (unsigned long *sz)
 	lock_warning = 0;
 	return NULL;
 #else
-	pages = mmap (0, *sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
+	pages = mmap (0, *sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
 	if (pages == MAP_FAILED) {
 		if (lock_warning)
 			fprintf (stderr, "couldn't map %lu bytes of private memory: %s\n", 
