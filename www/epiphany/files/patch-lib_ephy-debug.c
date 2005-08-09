--- lib/ephy-debug.c.orig	Tue Aug  9 13:28:12 2005
+++ lib/ephy-debug.c	Tue Aug  9 13:34:23 2005
@@ -23,7 +23,9 @@
 #include "ephy-debug.h"
 
 #include <string.h>
+#ifdef __linux__
 #include <execinfo.h>
+#endif
 #include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -107,6 +109,7 @@ trap_handler (const char *log_domain,
 
 			raise (SIGSTOP);
 		}
+#ifdef __linux__
 		else if (strcmp (ephy_debug_break, "stack") == 0)
 		{
 			void *array[MAX_DEPTH];
@@ -115,6 +118,7 @@ trap_handler (const char *log_domain,
 			size = backtrace (array, MAX_DEPTH);
 			backtrace_symbols_fd (array, size, 2);
 		}
+#endif
 		else if (strcmp (ephy_debug_break, "trap") == 0)
 		{
 			/* FIXME: disable the handler for a moment so we 
