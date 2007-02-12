--- src/sysinfo.cpp.orig	Sat Feb 10 09:00:25 2007
+++ src/sysinfo.cpp	Mon Feb 12 11:37:25 2007
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
@@ -240,6 +242,29 @@
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
@@ -247,9 +272,12 @@
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
