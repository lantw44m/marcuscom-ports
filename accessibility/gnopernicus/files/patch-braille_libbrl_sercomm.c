--- braille/libbrl/sercomm.c.orig	Mon Jan 12 12:51:01 2004
+++ braille/libbrl/sercomm.c	Mon Jan 12 18:20:42 2004
@@ -138,7 +138,7 @@
 
 	/* choose raw output */
 	// options.c_oflag &= ~OPOST;	
-	options.c_oflag &= ~OLCUC;
+	/*options.c_oflag &= ~OLCUC;*/
 	options.c_oflag &= ~ONLCR;
 	options.c_oflag &= ~OCRNL;
 	// options.c_oflag &= ~NOCR;
