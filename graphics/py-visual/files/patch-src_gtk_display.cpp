--- src/gtk2/display.cpp.orig	2009-09-28 01:08:27.000000000 +0200
+++ src/gtk2/display.cpp	2009-09-28 01:08:43.000000000 +0200
@@ -400,7 +400,7 @@ display::create()
 		window->fullscreen();
 	active = true;
 	area->grab_focus();
-	assert( area->can_focus());
+	assert( area->get_can_focus());
 	while (Gtk::Main::events_pending())
 		Gtk::Main::iteration();
 }
