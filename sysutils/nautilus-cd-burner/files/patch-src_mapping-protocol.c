--- src/mapping-protocol.c.orig	Sun Aug 20 08:47:20 2006
+++ src/mapping-protocol.c	Tue Aug 29 16:39:11 2006
@@ -26,6 +26,8 @@
 
 #include "config.h"
 
+#include <sys/types.h>
+#include <sys/time.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
@@ -86,6 +88,7 @@ static gboolean handle_write            
 #ifdef DEBUG_ENABLE
 
 static FILE *debug_out = NULL;
+static gboolean at_eof = FALSE;
 
 static void
 debug_init (void)
@@ -1189,6 +1192,9 @@ mapping_protocol_channel_fill_read_buffe
 
 	status = g_io_channel_read_chars (channel->iochannel, data, count, &length, NULL);
 
+	if (status == G_IO_STATUS_EOF) {
+		at_eof = TRUE;
+	}
 	if (status != G_IO_STATUS_NORMAL) {
 		return;
 	}
@@ -1340,7 +1346,7 @@ handle_read (GIOChannel             *sou
 		mapping_protocol_channel_do_iteration (channel);
 	}
 
-	if (condition & G_IO_HUP) {
+	if (condition & G_IO_HUP || at_eof) {
 		channel->read_watch_id = 0;
 		res = FALSE;
 		/* send a NULL message to signal error */
