--- hald/device_store.c.orig	2008-03-15 19:15:15.000000000 -0400
+++ hald/device_store.c	2008-03-15 19:16:30.000000000 -0400
@@ -292,6 +292,9 @@ hal_device_store_remove (HalDeviceStore 
 					      (gpointer)emit_device_property_changed,
 					      store);
 	g_signal_handlers_disconnect_by_func (device,
+					      (gpointer)device_pre_property_changed,
+					      store);
+	g_signal_handlers_disconnect_by_func (device,
 					      (gpointer)emit_device_capability_added,
 					      store);
 	g_signal_handlers_disconnect_by_func (device,
