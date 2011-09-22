libxul 1.9.2.x doesn't support this yet.

http://git.gnome.org/browse/gjs/commit/?id=72bc4307860a315f9d2173d700582add938d79a0

--- gi/object.c.orig	2011-09-22 17:15:11.000000000 +0200
+++ gi/object.c	2011-09-22 17:17:46.000000000 +0200
@@ -674,7 +674,6 @@
         if (unthreadsafe_template_for_constructor.gobj == NULL) {
             GParameter *params;
             int n_params;
-            GTypeQuery query;
 
             gtype = g_registered_type_info_get_g_type( (GIRegisteredTypeInfo*) priv->info);
             if (gtype == G_TYPE_NONE) {
@@ -693,9 +692,6 @@
             priv->gobj = g_object_newv(gtype, n_params, params);
             free_g_params(params, n_params);
 
-            g_type_query(gtype, &query);
-            JS_updateMallocCounter(context, query.instance_size);
-
             if (G_IS_INITIALLY_UNOWNED(priv->gobj) &&
                 !g_object_is_floating(priv->gobj)) {
                 /* GtkWindow does not return a ref to caller of g_object_new.
