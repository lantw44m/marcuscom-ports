--- glib-2.25.7/glib/gvariant-serialiser.c	2010-05-24 18:39:22.000000000 +0200
+++ glib/gvariant-serialiser.c	2010-05-25 18:10:30.000000000 +0200
@@ -139,6 +139,24 @@
   else
     g_assert (serialised.size == 0 || serialised.data != NULL);
 
+  /* Depending on the native alignment requirements of the machine, the
+   * compiler will insert either 3 or 7 padding bytes after the char.
+   * This will result in the sizeof() the struct being 12 or 16.
+   * Subtract 9 to get 3 or 7 which is a nice bitmask to apply to get
+   * the alignment bits that we "care about" being zero: in the
+   * 4-aligned case, we care about 2 bits, and in the 8-aligned case, we
+   * care about 3 bits.
+   */
+  alignment &= sizeof (struct {
+                         char a;
+                         union {
+                           guint64 x;
+                           void *y;
+                           gdouble z;
+                         } b;
+                       }
+                      ) - 9;
+
   g_assert_cmpint (alignment & (gsize) serialised.data, ==, 0);
 }
 
