Index: src/place.c
===================================================================
RCS file: /cvs/gnome/metacity/src/place.c,v
retrieving revision 1.43
diff -p -u -r1.43 place.c
--- src/place.c	25 Jul 2005 02:12:58 -0000	1.43
+++ src/place.c	28 Jul 2005 16:42:05 -0000
@@ -369,20 +369,6 @@ avoid_being_obscured_as_second_modal_dia
                   "focus window\n",
                   window->desc);
     }
-
-  meta_topic (META_DEBUG_PLACEMENT,
-              "Status:\n"
-              "  denied focus: %d\n"
-              "  modal:        %d\n"
-              "  same app:     %d\n"
-              "  overlaps      %d\n",
-              window->denied_focus_and_not_transient,
-              window->wm_state_modal,
-              meta_window_same_application (window, focus_window),
-              meta_rectangle_intersect (&window->rect,
-                                        &focus_window->rect,
-                                        &overlap)
-              );
 }
 
 static int
