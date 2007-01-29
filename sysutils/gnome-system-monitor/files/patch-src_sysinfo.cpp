--- src/sysinfo.cpp.orig	Mon Jan 22 12:01:12 2007
+++ src/sysinfo.cpp	Sun Jan 28 21:10:13 2007
@@ -13,6 +13,9 @@
 #include <sys/socket.h>
 #include <sys/wait.h>
 #include <math.h>
+#ifdef __FreeBSD__
+#include <sys/utsname.h>
+#endif
 
 #include <string>
 #include <vector>
@@ -195,6 +198,29 @@ namespace {
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
@@ -202,8 +228,11 @@ namespace {
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
 
