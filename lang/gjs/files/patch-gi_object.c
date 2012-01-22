libxul 1.9.2.x doesn't support this yet.

http://git.gnome.org/browse/gjs/commit/?id=72bc4307860a315f9d2173d700582add938d79a0

--- gi/object.c.orig	2012-01-22 11:53:37.000000000 +0100
+++ gi/object.c	2012-01-22 11:54:37.000000000 +0100
@@ -674,7 +674,6 @@ GJS_NATIVE_CONSTRUCTOR_DECLARE(object_in
         if (unthreadsafe_template_for_constructor.gobj == NULL) {
             GParameter *params;
             int n_params;
-            GTypeQuery query;
             JSObject *old_jsobj;
 
             gtype = g_registered_type_info_get_g_type( (GIRegisteredTypeInfo*) priv->info);
@@ -711,9 +710,6 @@ GJS_NATIVE_CONSTRUCTOR_DECLARE(object_in
                 goto out;
             }
 
-            g_type_query(gtype, &query);
-            JS_updateMallocCounter(context, query.instance_size);
-
             if (G_IS_INITIALLY_UNOWNED(priv->gobj) &&
                 !g_object_is_floating(priv->gobj)) {
                 /* GtkWindow does not return a ref to caller of g_object_new.
