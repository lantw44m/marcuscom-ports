--- src/netstatus-sysdeps.c.orig	Mon Jun  9 13:18:04 2003
+++ src/netstatus-sysdeps.c	Fri Dec  5 18:47:38 2003
@@ -31,6 +31,8 @@
 #include <glib.h>
 #include <libgnome/gnome-i18n.h>
 
+#if !defined(__FreeBSD__)
+
 static inline char *
 parse_iface_name (const char *buf)
 {
@@ -206,3 +208,145 @@
 
   return error_message;
 }
+
+#else
+
+static inline void
+parse_header (char *buf,
+	      int  *prx_idx,
+	      int  *ptx_idx,
+	      int  *brx_idx,
+	      int  *btx_idx)
+{
+   char *p;
+   int   i;
+
+   *prx_idx = *ptx_idx = -1;
+   *brx_idx = *btx_idx = -1;
+
+   p = strtok (buf, " ");
+   for (i = 0; p; i++, p = strtok (NULL, " "))
+     {
+        if (!strcmp (p, "Ipkts"))
+	  {
+	     *prx_idx = i;
+	  }
+	else if (!strcmp (p, "Ibytes"))
+	  {
+	     *brx_idx = i;
+	  }
+	else if (!strcmp (p, "Opkts"))
+	  {
+	     *ptx_idx = i;
+	  }
+	else if (!strcmp (p, "Obytes"))
+	  {
+	     *btx_idx = i;
+	  }
+     }
+}
+
+static inline int
+parse_stats (char  *buf,
+	     int    prx_idx,
+	     int    ptx_idx,
+	     long  *in_packets,
+	     long  *out_packets,
+	     int    brx_idx,
+	     int    btx_idx,
+	     long  *in_bytes,
+	     long  *out_bytes)
+{
+   char *p;
+   int   i;
+
+   p = strtok (buf, " ");
+   for (i = 0; p; i++, p = strtok (NULL, " "))
+     {
+        if (i == prx_idx)
+	   *in_packets = g_ascii_strtoull (p, NULL, 10);
+	if (i == ptx_idx)
+	   *out_packets = g_ascii_strtoull (p, NULL, 10);
+	if (i == brx_idx)
+	   *in_bytes = g_ascii_strtoull (p, NULL, 10);
+	if (i == btx_idx)
+	   *out_bytes = g_ascii_strtoull (p, NULL, 10);
+     }
+ 
+   if (i <= prx_idx || i <= ptx_idx || i <= brx_idx || i <=btx_idx)
+      return FALSE;
+
+   return TRUE;
+}
+
+char *
+netstatus_sysdeps_read_iface_statistics (const char *iface,
+					 long       *in_packets,
+					 long       *out_packets,
+					 long       *in_bytes,
+					 long       *out_bytes)
+{
+   gchar *buf;
+   gchar cmd[512];
+   gchar **command_line;
+   int prx_idx, ptx_idx;
+   int brx_idx, btx_idx;
+   char *error_message = NULL;
+   gchar *dir = g_get_current_dir ();
+   gint pout;
+   GIOChannel *channel;
+   GError *err = NULL;
+
+   *in_packets = -1;
+   *out_packets = -1;
+   *in_bytes = -1;
+   *out_bytes = -1;
+
+   g_snprintf (cmd, sizeof(cmd), "/usr/bin/netstat -I %s -b -f inet",
+	   	     iface);
+   command_line = g_strsplit (cmd, " ", -1);
+
+   if (g_spawn_async_with_pipes (dir, command_line, NULL,
+	       			 G_SPAWN_FILE_AND_ARGV_ZERO, NULL,
+				 NULL, NULL, NULL, &pout,
+				 NULL, &err)) {
+       g_strfreev (command_line);
+       channel = g_io_channel_unix_new (pout);
+       g_io_channel_read_line (channel, &buf, NULL, NULL, NULL);
+
+       parse_header (buf, &prx_idx, &ptx_idx, &brx_idx, &btx_idx);
+       if (prx_idx == -1 || ptx_idx == -1 ||
+	   brx_idx == -1 || btx_idx == -1)
+	 return g_strdup ("Could not parse netstat output.  Unknown format.");
+
+       g_io_channel_read_line (channel, &buf, NULL, NULL, NULL);
+
+       if (!parse_stats (buf, prx_idx, ptx_idx, in_packets, out_packets,
+	       	    brx_idx, btx_idx, in_bytes, out_bytes))
+       {
+	  if (error_message)
+	     g_free (error_message);
+	  error_message = g_strdup_printf (_("Could not parse interface statistics from '%s'. "
+		      	     "prx_idx = %d; ptx_idx = %d; brx_idx = %d; btx_idx = %d;"),
+		  	     buf, prx_idx, ptx_idx, brx_idx, btx_idx);
+       }
+
+       if ((*in_packets == -1 || *out_packets == -1 || *in_bytes == -1 || *out_bytes == -1) && !error_message)
+	   error_message = g_strdup_printf ("Could not obtain information on interface '%s' from netstat", iface);
+
+       g_io_channel_unref (channel);
+       g_io_channel_shutdown (channel, TRUE, NULL);
+   }
+   else {
+      if (error_message)
+         g_free (error_message);
+      error_message = g_strdup_printf ("Error running /usr/bin/netstat for '%s': %s", iface,
+	      	       err->message);
+      g_error_free (err);
+   }
+
+   g_free (dir);
+
+   return error_message;
+}
+#endif
