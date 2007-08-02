--- gnome-breakpad/gnome-breakpad.cc.orig	2007-08-02 02:21:43.000000000 -0400
+++ gnome-breakpad/gnome-breakpad.cc	2007-08-02 02:30:01.000000000 -0400
@@ -6,7 +6,9 @@
 #include <cassert>
 #include <cstring>
 
+#ifdef __linux__
 #include <libelf.h>
+#endif
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
@@ -30,6 +32,7 @@ static bool    run_bug_buddy   (const gc
 
 static gchar *bugbuddy;
 
+#ifdef __linux__
 // Callback when minidump written.
 static bool MinidumpCallback(const char *dump_path,
                              const char *minidump_id,
@@ -80,6 +83,7 @@ elf_has_debug_symbols (char *filename)
        /* no symtab */
        return false;
 }
+#endif
 
 
 
@@ -182,9 +186,13 @@ check_if_gdb (void *callback_context)
 		_exit(0);
 	}
 	
+#ifdef __linux__
 	memset(mypath, 0, sizeof(mypath));
 	readlink ("/proc/self/exe", mypath, sizeof(mypath));
 	has_debug_symbols = elf_has_debug_symbols (mypath);
+#else
+	has_debug_symbols = true;
+#endif
 
 
 	if (bugbuddy && gdb && has_debug_symbols) {
@@ -204,7 +212,11 @@ gtk_module_init (int *argc, char** argv[
 	
 	if (bugbuddy && !g_getenv ("GNOME_DISABLE_CRASH_DIALOG")) {
   		static ExceptionHandler handler("/tmp", check_if_gdb,
+#ifdef __linux__
 						MinidumpCallback, NULL, true);
+#else
+						NULL, NULL, true);
+#endif
 	}
   
 }
