--- dvd_plus_rw_utils.cpp.orig	Tue Mar  1 00:44:47 2005
+++ dvd_plus_rw_utils.cpp	Tue Mar  1 00:45:05 2005
@@ -223,8 +223,8 @@
     wait_for_unit (cmd);
   } while (once--);
 
-  if (profile==0 || (profile&0x30)==0)	// no or non-DVD media...
-    return profile;
+  //if (profile==0 || (profile&0x30)==0)	// no or non-DVD media...
+    //return profile;
 
   cmd[0] = 0x51;	// READ DISC INFORMATION
   cmd[8] = sizeof(disc_info);
