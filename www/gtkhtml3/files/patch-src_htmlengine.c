--- src/htmlengine.c.orig	Mon Apr 21 03:08:19 2003
+++ src/htmlengine.c	Mon Apr 21 03:08:50 2003
@@ -4142,6 +4142,7 @@
 	if (e->editable) {
 		html_engine_ensure_editable (e);
 		html_cursor_home (e->cursor, e);
+		e->newPage = FALSE;
 	}
 
 	g_signal_emit (e, signals [LOAD_DONE], 0);
@@ -4577,6 +4578,7 @@
 	if (editable) {
 		html_engine_ensure_editable (e);
 		html_cursor_home (e->cursor, e);
+		e->newPage = FALSE;
 
 		if (e->have_focus)
 			html_engine_setup_blinking_cursor (e);
