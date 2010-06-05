--- gdk/gdkmm/device.cc.orig	2010-06-06 00:32:40.000000000 +0200
+++ gdk/gdkmm/device.cc	2010-06-06 00:34:00.000000000 +0200
@@ -189,7 +189,7 @@
 gdk_device_get_state(gobj(), Glib::unwrap(window), &(axes), ((GdkModifierType*) &(mask))); 
 }
 
-bool Device::get_history(const Glib::RefPtr<Window>& window, guint32 start, guint32 stop, GdkTimeCoord**& events, int& n_events)
+bool Device::get_history(const Glib::RefPtr<Window>& window, guint32 start, guint32 stop, GdkTimeCoord**& events, guint& n_events)
 {
   return gdk_device_get_history(gobj(), Glib::unwrap(window), start, stop, &(events), &n_events);
 }
