From 1ae30806403e556c8297a16a25a18687d9e80f89 Mon Sep 17 00:00:00 2001
From: Stef Walter <stefw@gnome.org>
Date: Thu, 28 Jun 2012 14:41:39 +0200
Subject: [PATCH] GTlsInteraction: Fix incorrect locking of mutex

 * Fix incorrect locking of mutex in g_tls_interaction_invoke_ask_password()

https://bugzilla.gnome.org/show_bug.cgi?id=678758
---
 gio/gtlsinteraction.c |    9 +++++++--
 1 file changed, 7 insertions(+), 2 deletions(-)

diff --git a/gio/gtlsinteraction.c b/gio/gtlsinteraction.c
index 41574b7..e921b81 100644
--- gio/gtlsinteraction.c
+++ gio/gtlsinteraction.c
@@ -321,6 +321,7 @@ g_tls_interaction_invoke_ask_password (GTlsInteraction    *interaction,
   GTlsInteractionResult result;
   InvokeClosure *closure;
   GTlsInteractionClass *klass;
+  gboolean complete;
 
   g_return_val_if_fail (G_IS_TLS_INTERACTION (interaction), G_TLS_INTERACTION_UNHANDLED);
   g_return_val_if_fail (G_IS_TLS_PASSWORD (password), G_TLS_INTERACTION_UNHANDLED);
@@ -348,12 +349,16 @@ g_tls_interaction_invoke_ask_password (GTlsInteraction    *interaction,
        */
       if (g_main_context_acquire (interaction->priv->context))
         {
-          while (!closure->complete)
+          for (;;)
             {
+              g_mutex_lock (&closure->mutex);
+              complete = closure->complete;
               g_mutex_unlock (&closure->mutex);
+              if (complete)
+                break;
               g_main_context_iteration (interaction->priv->context, TRUE);
-              g_mutex_lock (&closure->mutex);
             }
+
           g_main_context_release (interaction->priv->context);
 
           if (closure->error)
-- 
1.7.10.2
