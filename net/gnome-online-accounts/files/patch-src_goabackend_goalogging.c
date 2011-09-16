--- src/goabackend/goalogging.c.orig	2011-08-25 15:50:26.000000000 +0200
+++ src/goabackend/goalogging.c	2011-09-16 14:58:16.000000000 +0200
@@ -207,7 +207,12 @@ goa_log (GoaLogLevel     level,
       break;
     }
 
+// sys_gettid return current pid
+#ifdef __linux__
   thread_str = g_strdup_printf ("%d", (gint) syscall (SYS_gettid));
+#else
+  thread_str = g_strdup_printf ("%d", (gint) getpid());
+#endif
   g_print ("%s%s%s.%03d:%s%s%s[%s]%s:%s%s%s:%s %s %s[%s, %s()]%s\n",
            _color_get (_COLOR_BOLD_ON), _color_get (_COLOR_FG_YELLOW), time_buf, (gint) now.tv_usec / 1000, _color_get (_COLOR_RESET),
            _color_get (_COLOR_FG_MAGENTA), _color_get (_COLOR_BOLD_ON), thread_str, _color_get (_COLOR_RESET),
