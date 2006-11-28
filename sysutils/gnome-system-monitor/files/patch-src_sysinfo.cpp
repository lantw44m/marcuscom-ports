--- src/sysinfo.cpp.orig	Fri Nov 24 02:41:14 2006
+++ src/sysinfo.cpp	Fri Nov 24 02:54:59 2006
@@ -11,6 +11,9 @@
 #include <unistd.h>
 #include <netdb.h>
 #include <sys/socket.h>
+#ifdef __FreeBSD__
+#include <sys/utsname.h>
+#endif
 
 #include <string>
 #include <vector>
@@ -140,16 +143,39 @@ namespace {
     }
   };
 
+  class FreeBSDSysInfo
+    : public SysInfo
+  {
+  public:
+    FreeBSDSysInfo()
+      : SysInfo("FreeBSD")
+    {
+      this->load_freebsd_info();
+    }
+
+  private:
+    void load_freebsd_info()
+    {
+	struct utsname name;
+
+	uname(&name);
+
+	this->distro_version = name.release;
+    }
+  };
 
   SysInfo* get_sysinfo()
   {
     if (g_file_test("/etc/debian_version", G_FILE_TEST_EXISTS))
       return new DebianSysInfo;
     else
+#ifdef __FreeBSD__
+      return new FreeBSDSysInfo;
+#else
       return new SysInfo(_("Unknown distro"));
+#endif
   }
 }
-
 
 GtkWidget *
 procman_create_sysinfo_view(void)
