--- cd-recorder.h.orig	Wed Dec 10 14:28:50 2003
+++ cd-recorder.h	Wed Dec 10 14:29:00 2003
@@ -31,7 +31,7 @@
     struct {
       char *filename;
     } data;
-  };
+  } contents;
 };
 
 #define CD_TYPE_RECORDER            (cd_recorder_get_type ())
