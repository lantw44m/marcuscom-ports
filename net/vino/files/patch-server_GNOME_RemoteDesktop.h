--- server/GNOME_RemoteDesktop.h.orig	Thu May 19 12:47:15 2005
+++ server/GNOME_RemoteDesktop.h	Thu May 19 12:52:53 2005
@@ -46,7 +46,7 @@ static
 #else
 extern
 #endif
-ORBIT2_MAYBE_CONST struct CORBA_TypeCode_struct TC_GNOME_RemoteDesktop_Shell_struct;
+const struct CORBA_TypeCode_struct TC_GNOME_RemoteDesktop_Shell_struct;
 #define TC_GNOME_RemoteDesktop_Shell ((CORBA_TypeCode)&TC_GNOME_RemoteDesktop_Shell_struct)
 #endif
 #endif
