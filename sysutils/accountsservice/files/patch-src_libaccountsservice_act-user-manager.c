From fbf7d277d2ff7e69795a7880a67104811e0fd4a5 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Tue, 27 Sep 2011 23:55:43 +0000
Subject: lib: Don't track non-graphical sessions

If a user happens to be logged in at a VT, we don't
want to show them as "already logged in" or whatever.

This commit filters out vt sessions in the same way it
filters out sessions associated with the login screen.
---
diff --git a/src/libaccountsservice/act-user-manager.c b/src/libaccountsservice/act-user-manager.c
index 2fd2394..3fea3dc 100644
--- src/libaccountsservice/act-user-manager.c
+++ src/libaccountsservice/act-user-manager.c
@@ -1340,6 +1340,12 @@ maybe_add_new_session (ActUserManagerNewSession *new_session)
 
         manager = ACT_USER_MANAGER (new_session->manager);
 
+        if (new_session->x11_display == NULL || new_session->x11_display[0] == '\0') {
+                g_debug ("AcUserManager: ignoring session '%s' since it's not graphical",
+                         new_session->id);
+                goto done;
+        }
+
         if (session_is_login_window (manager, new_session->id)) {
                 goto done;
         }
--
cgit v0.9.0.2-2-gbebe
