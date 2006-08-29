--- src/mapping-protocol.c.orig	Sun Aug 20 08:47:20 2006
+++ src/mapping-protocol.c	Tue Aug 29 10:53:50 2006
@@ -26,6 +26,8 @@
 
 #include "config.h"
 
+#include <sys/types.h>
+#include <sys/time.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
@@ -1188,6 +1190,13 @@ mapping_protocol_channel_fill_read_buffe
 	}
 
 	status = g_io_channel_read_chars (channel->iochannel, data, count, &length, NULL);
+
+	if (status == G_IO_STATUS_EOF) {
+		channel->read_watch_id = 0;
+		if (channel->message_handler != NULL) {
+			channel->message_handler (channel, NULL, channel->user_data);
+		}
+	}
 
 	if (status != G_IO_STATUS_NORMAL) {
 		return;
