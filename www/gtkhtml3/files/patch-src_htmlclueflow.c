--- src/htmlclueflow.c.orig	Thu Feb 10 01:33:39 2005
+++ src/htmlclueflow.c	Thu Feb 10 01:34:00 2005
@@ -2362,10 +2362,11 @@
 		HTMLObject *child;
 		for (child = HTML_CLUE (o)->head; child; child = child->next) {
 			if (HTML_IS_TEXT (child)) {
+				PangoDirection pdir;
 				if (child == HTML_CLUE (o)->head && html_object_get_length (child) == 0 && o->prev)
 					return html_object_get_direction (o->prev);
 
-				PangoDirection pdir = html_text_get_pango_direction (HTML_TEXT (child));
+				pdir = html_text_get_pango_direction (HTML_TEXT (child));
 				switch (pdir) {
 				case PANGO_DIRECTION_RTL:
 					dir = HTML_DIRECTION_RTL;
