--- src/sysinfo.cpp.orig	Mon Nov 20 15:41:52 2006
+++ src/sysinfo.cpp	Mon Dec  4 13:39:52 2006
@@ -8,9 +8,14 @@
 #include <glibtop/mem.h>
 #include <glibtop/sysinfo.h>
 
+#include <sys/types.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #include <netdb.h>
 #include <sys/socket.h>
+#ifdef __FreeBSD__
+#include <sys/utsname.h>
+#endif
 
 #include <string>
 #include <vector>
@@ -191,6 +196,29 @@ namespace {
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
@@ -198,8 +226,11 @@ namespace {
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
 
