--- Src/Gtk2/speech.cc.orig	Wed Feb 23 02:30:15 2005
+++ Src/Gtk2/speech.cc	Wed Feb 23 02:30:44 2005
@@ -78,7 +78,8 @@
 void teardown_speech() {
 
   bonobo_object_release_unref (speaker, NULL);
-  CORBA_free (voices);
+  if (voices != NULL && voices->_length != 0)
+    CORBA_free (voices);
   CORBA_exception_free (&ev);
 
 }
