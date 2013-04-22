From 7a4c59faf5f7cb7a1419dc5b26d154f1a8007423 Mon Sep 17 00:00:00 2001
From: Morten Welinder <terra@gnome.org>
Date: Sun, 10 Mar 2013 20:56:37 +0000
Subject: Compilation: work around gtk-doc for --without-long-double builds.

---
(limited to 'goffice/math/go-cspline.c')

diff --git a/goffice/math/go-cspline.c b/goffice/math/go-cspline.c
index d321847..307f6f7 100644
--- goffice/math/go-cspline.c
+++ goffice/math/go-cspline.c
@@ -50,6 +50,12 @@
 #define DOUBLE long double
 #define SUFFIX(_n) _n ## l
 #define LONG_DOUBLE
+
+#else
+/* It appears that gtk-doc is too dumb to handle this file.  Provide
+   a dummy type getter to make things work.  */
+GType go_csplinel_get_type (void);
+GType go_csplinel_get_type (void) { return G_TYPE_NONE; }
 #endif
 
 #endif
--
cgit v0.9.1
From 01f93869b7e2e9b38bd62c94d9d71103dffa4f08 Mon Sep 17 00:00:00 2001
From: Morten Welinder <terra@gnome.org>
Date: Sun, 10 Mar 2013 20:18:01 +0000
Subject: Math: fix problems with cspline boxed type.

---
(limited to 'goffice/math/go-cspline.c')

diff --git a/goffice/math/go-cspline.c b/goffice/math/go-cspline.c
index a3d0991..d321847 100644
--- goffice/math/go-cspline.c
+++ goffice/math/go-cspline.c
@@ -229,9 +229,9 @@ SUFFIX(go_cspline_ref) (GOCSpline *sp)
 
 GType
 #ifdef LONG_DOUBLE
-go_cspline_get_type (void)
-#else
 go_csplinel_get_type (void)
+#else
+go_cspline_get_type (void)
 #endif
 {
 	static GType t = 0;
@@ -239,9 +239,9 @@ go_csplinel_get_type (void)
 	if (t == 0) {
 		t = g_boxed_type_register_static (
 #ifdef LONG_DOUBLE
-		     "GOCSpline",
-#else
 		     "GOCSplinel",
+#else
+		     "GOCSpline",
 #endif
 			 (GBoxedCopyFunc)SUFFIX(go_cspline_ref),
 			 (GBoxedFreeFunc)SUFFIX(go_cspline_destroy));
--
cgit v0.9.1
