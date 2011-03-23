--- editor/dconf-model.c.orig	2011-03-22 16:59:25.000000000 +0100
+++ editor/dconf-model.c	2011-03-23 14:53:41.000000000 +0100
@@ -2303,7 +2303,7 @@
 	_tmp2_ = schema_list_new ();
 	_schema_list_unref0 (self->schemas);
 	self->schemas = _tmp2_;
-	schema_list_load_directory (self->schemas, "/usr/share/glib-2.0/schemas", &_inner_error_);
+	schema_list_load_directory (self->schemas, "/usr/local/share/glib-2.0/schemas", &_inner_error_);
 	if (_inner_error_ != NULL) {
 		goto __catch3_g_error;
 	}
