--- include/orbit/poa/poa.h.orig	Tue Jun 17 01:34:57 2003
+++ include/orbit/poa/poa.h	Tue Jun 17 01:35:58 2003
@@ -143,6 +143,9 @@
 
 /* DEPRECATED */
 void ORBit_classinfo_register  (PortableServer_ClassInfo   *ci);
+#define ORBIT_SERVANT_SET_CLASSINFO(servant,ci) G_STMT_START {		\
+    ((PortableServer_ServantBase *)(servant))->vepv[0]->_private = (ci);\
+} G_STMT_END
 
 #endif /* defined(ORBIT2_INTERNAL_API) || defined (ORBIT2_STUBS_API) */
 
