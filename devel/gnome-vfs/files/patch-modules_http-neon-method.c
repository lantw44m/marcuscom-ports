--- modules/http-neon-method.c.orig	Thu Jul 22 16:05:32 2004
+++ modules/http-neon-method.c	Thu Jul 22 16:05:52 2004
@@ -497,8 +497,8 @@
 static gboolean
 http_auth_cache_cleanup (gpointer *data)
 {
-	DEBUG_HTTP ("[AuthCache] Cleanup!");
 	gboolean restart_timeout;
+	DEBUG_HTTP ("[AuthCache] Cleanup!");
 
 	restart_timeout = FALSE;
 
@@ -1324,8 +1324,8 @@
 static gboolean
 neon_session_pool_cleanup (gpointer *data)
 {
-	DEBUG_HTTP ("[Session Pool] Cleanup!");
 	gboolean restart_timeout;
+	DEBUG_HTTP ("[Session Pool] Cleanup!");
 
 	restart_timeout = FALSE;
 
