--- editor/dconf-model.c.orig	2011-03-19 23:04:18.000000000 +0100
+++ editor/dconf-model.c	2011-03-19 23:05:20.000000000 +0100
@@ -2170,7 +2170,7 @@ SettingsModel* settings_model_construct 
 	_tmp5_ = _tmp4_;
 	_schema_list_unref0 (self->schemas);
 	self->schemas = _tmp5_;
-	schema_list_load_directory (self->schemas, "/usr/share/glib-2.0/schemas", &_inner_error_);
+	schema_list_load_directory (self->schemas, "/usr/local/share/glib-2.0/schemas", &_inner_error_);
 	if (_inner_error_ != NULL) {
 		goto __catch3_g_error;
 	}
