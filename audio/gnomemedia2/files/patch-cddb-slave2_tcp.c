--- cddb-slave2/tcp.c.orig	Sat Mar 12 02:32:52 2005
+++ cddb-slave2/tcp.c	Sat Mar 12 02:39:55 2005
@@ -171,6 +171,9 @@ gnet_tcp_socket_new_async (const GInetAd
   struct sockaddr_in6* 	sa_in6;
   struct sockaddr_in6 	sa6;
   int ifindex;
+#define SS_LEN ss_len
+#else
+#define SS_LEN sa_len
 #endif
   struct sockaddr_in* 	sa_in;
   struct sockaddr	sa;
@@ -265,7 +268,7 @@ gnet_tcp_socket_new_async (const GInetAd
 		continue;
 
 	      sa_in6->sin6_scope_id = ifindex;
-	      con = connect (s->sockfd, (struct sockaddr *)&sa6, sizeof(s->sa));
+	      con = connect (s->sockfd, (struct sockaddr *)&sa6, s->sa.SS_LEN);
 	      if (con == 0 || errno == EINPROGRESS)
 				break;
 
@@ -283,7 +286,7 @@ gnet_tcp_socket_new_async (const GInetAd
       memcpy(&sa, &addr->sa, sizeof(sa));
       sa_in = (struct sockaddr_in *) &sa;
       sa_in->sin_family = AF_INET;
-      con = connect(s->sockfd, &sa, sizeof(s->sa));
+      con = connect(s->sockfd, &sa, s->sa.SS_LEN);
     }
 
   /* Connect (but non-blocking!) */
