--- src/sysinfo.cpp.orig	Thu Dec 14 17:51:28 2006
+++ src/sysinfo.cpp	Sun Dec 17 21:17:34 2006
@@ -12,6 +12,9 @@
 #include <netdb.h>
 #include <sys/socket.h>
 #include <sys/wait.h>
+#ifdef __FreeBSD__
+#include <sys/utsname.h>
+#endif
 
 #include <string>
 #include <vector>
@@ -190,6 +193,29 @@ namespace {
     }
   };
 
+#ifdef __FreeBSD__
+  class UnameSysInfo
+      : public SysInfo
+  {
+      public:
+	  UnameSysInfo()
+	  {
+	      this->load_uname_info();
+	  }
+
+      private:
+
+	  void load_uname_info()
+	  {
+	      struct utsname name;
+
+	      uname(&name);
+
+	      this->distro_name = name.sysname;
+	      this->distro_release = name.release;
+	  }
+  };
+#endif
 
   SysInfo* get_sysinfo()
   {
@@ -197,8 +223,11 @@ namespace {
       g_free(p);
       return new LSBSysInfo;
     }
-
+#ifdef __FreeBSD__
+    return new UnameSysInfo;
+#else
     return new SysInfo(_("Unknown distribution"));
+#endif
   }
 }
 
