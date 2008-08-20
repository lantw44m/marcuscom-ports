--- src/malloc.c.orig	2008-08-20 13:22:07.000000000 -0400
+++ src/malloc.c	2008-08-20 13:22:31.000000000 -0400
@@ -58,3 +58,29 @@ char *ca_sprintf_malloc(const char *form
             size *= 2;
     }
 }
+
+#ifndef HAVE_STRNDUP
+char *ca_strndup (const char *s, size_t n) {
+    size_t n_avail;
+    char *p;
+
+    if (!s) {
+        return NULL;
+    }
+
+    if (memchr (s, '\0', n) != NULL) {
+        n_avail = strlen (s);
+        if (n_avail > n)
+            n_avail = n;
+    } else {
+        n_avail = n;
+    }
+    p = ca_malloc (n_avail + 1);
+    if (p == NULL)
+        return NULL;
+    memcpy (p, s, n_avail);
+    p[n_avail] = '\0';
+
+    return p;
+}
+#endif
