This file is only needed until the next dasher version comes out.
It's just a fix to make dasher build against the new libwnck API.

--- Src/Gtk2/edit.cc.orig	Wed Mar  2 19:38:45 2005
+++ Src/Gtk2/edit.cc	Wed Mar  2 19:38:55 2005
@@ -186,7 +186,7 @@
     break;
   case 31:
 	  if (pointer!=NULL) {
-		  wnck_window_activate((WnckWindow *)pointer);
+		  wnck_window_activate((WnckWindow *)pointer, CurrentTime);
 	  }
 	  break;
 #endif
