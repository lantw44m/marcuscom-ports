--- glib/gvariant-serialiser.c.orig	2010-05-24 18:39:22.000000000 +0200
+++ glib/gvariant-serialiser.c	2010-05-28 11:03:39.000000000 +0200
@@ -129,7 +129,7 @@
 g_variant_serialised_check (GVariantSerialised serialised)
 {
   gsize fixed_size;
-  guint alignment;
+  gsize alignment;
 
   g_assert (serialised.type_info != NULL);
   g_variant_type_info_query (serialised.type_info, &alignment, &fixed_size);
@@ -139,6 +139,34 @@
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
+  /* Some OSes (FreeBSD is a known example) have a malloc() that returns
+   * unaligned memory if you request small sizes.  'malloc (1);', for
+   * example, has been seen to return pointers aligned to 6 mod 16.
+   *
+   * Check if this is a small allocation and return without enforcing
+   * the alignment assertion if this is the case.
+   */
+  if (serialised.size <= alignment)
+    return;
+
   g_assert_cmpint (alignment & (gsize) serialised.data, ==, 0);
 }
 
