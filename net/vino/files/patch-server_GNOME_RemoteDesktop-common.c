--- server/GNOME_RemoteDesktop-common.c.orig	Thu May 19 12:53:21 2005
+++ server/GNOME_RemoteDesktop-common.c	Thu May 19 12:53:53 2005
@@ -41,7 +41,7 @@ _impl_dummy (_o_servant, _o_ev);
 #ifdef ORBIT_IDL_C_IMODULE_GNOME_RemoteDesktop
 static
 #endif
-ORBIT2_MAYBE_CONST struct CORBA_TypeCode_struct TC_GNOME_RemoteDesktop_Shell_struct = {
+const struct CORBA_TypeCode_struct TC_GNOME_RemoteDesktop_Shell_struct = {
 {&ORBit_TypeCode_epv, ORBIT_REFCOUNT_STATIC},
 CORBA_tk_objref,
 0,
