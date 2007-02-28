--- src/sysinfo.cpp.orig	Tue Feb 27 01:52:44 2007
+++ src/sysinfo.cpp	Wed Feb 28 00:17:06 2007
@@ -14,11 +14,13 @@
 #include <sys/wait.h>
 #include <math.h>
 #include <errno.h>
-
 #include <string>
 #include <vector>
 #include <fstream>
 #include <sstream>
+#ifdef __FreeBSD__
+#include <sys/utsname.h>
+#endif
 
 #include "sysinfo.h"
 #include "util.h"
@@ -243,6 +245,30 @@ namespace {
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
+	      this->distro_codename = name.machine;
+	  }
+  };
+#endif
 
   SysInfo* get_sysinfo()
   {
@@ -250,9 +276,12 @@ namespace {
       g_free(p);
       return new LSBSysInfo;
     }
+#ifdef __FreeBSD__
+      return new UnameSysInfo;
+#else
     else if (g_file_test("/etc/release", G_FILE_TEST_EXISTS))
       return new SolarisSysInfo;
-
+#endif
     return new SysInfo(_("Unknown distribution"));
   }
 }
