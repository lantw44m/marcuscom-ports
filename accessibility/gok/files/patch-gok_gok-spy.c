--- gok/gok-spy.c.orig	Mon Mar  1 17:20:20 2004
+++ gok/gok-spy.c	Mon Mar  1 17:21:24 2004
@@ -1287,8 +1287,9 @@
 			while (parent && Accessible_getChildCount (parent) == 1) 
 			{
 				char *tmp;
+				Accessible *tmp_parent;
 				if (maxloops-- < 1) { break; }  /* guard against erroneous cyclic parent/child relations */
-				Accessible *tmp_parent = parent;
+				tmp_parent = parent;
 				tmp = Accessible_getName (tmp_parent); 
 				if (tmp != NULL) 
 				{
