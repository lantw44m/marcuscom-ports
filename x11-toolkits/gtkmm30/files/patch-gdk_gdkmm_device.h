--- gdk/gdkmm/device.h.orig	2010-06-06 00:34:40.000000000 +0200
+++ gdk/gdkmm/device.h	2010-06-06 00:34:55.000000000 +0200
@@ -193,7 +193,7 @@
    * @return <tt>true</tt> if the windowing system supports motion history and
    * at least one event was found.
    */
-  bool get_history(const Glib::RefPtr<Window>& window, guint32 start, guint32 stop, GdkTimeCoord**& events, int& n_events);
+  bool get_history(const Glib::RefPtr<Window>& window, guint32 start, guint32 stop, GdkTimeCoord**& events, guint& n_events);
   
   /** Interprets an array of double as axis values for a given device,
    * and locates the value in the array for a given axis use.
