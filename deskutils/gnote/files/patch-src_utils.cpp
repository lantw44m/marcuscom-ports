--- src/utils.cpp.orig	2009-09-27 13:43:28.000000000 +0200
+++ src/utils.cpp	2009-09-27 13:46:05.000000000 +0200
@@ -744,7 +744,7 @@ namespace gnote {
       if (!group_cycling) {
         activate();
       } 
-      else if (can_focus()) {
+      else if (get_can_focus()) {
         grab_focus();
       }
 
