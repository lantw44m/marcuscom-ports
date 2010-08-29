--- gio/gsocket.c.orig	2010-08-29 18:57:52.000000000 -0400
+++ gio/gsocket.c	2010-08-29 18:57:55.000000000 -0400
@@ -2893,8 +2893,13 @@ g_socket_send_message (GSocket          
       for (i = 0; i < num_messages; i++)
 	msg.msg_controllen += CMSG_SPACE (g_socket_control_message_get_size (messages[i]));
 
-      msg.msg_control = g_alloca (msg.msg_controllen);
-      memset (msg.msg_control, '\0', msg.msg_controllen);
+      if (msg.msg_controllen == 0)
+        msg.msg_control = NULL;
+      else
+        {
+          msg.msg_control = g_alloca (msg.msg_controllen);
+          memset (msg.msg_control, '\0', msg.msg_controllen);
+        }
 
       cmsg = CMSG_FIRSTHDR (&msg);
       for (i = 0; i < num_messages; i++)
