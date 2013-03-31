From 6666b3cd99a4931bd28b622918c121f92cf33b52 Mon Sep 17 00:00:00 2001
From: Xan Lopez <xan@igalia.com>
Date: Tue, 26 Mar 2013 15:20:38 +0000
Subject: soup-session: fix memory leak

Do not steal the stream from the GTask, otherwise its destruction
method will never run and it will be leaked.

https://bugzilla.gnome.org/show_bug.cgi?id=696594
---
diff --git a/libsoup/soup-session.c b/libsoup/soup-session.c
index 14e2be4..186d57a 100644
--- libsoup/soup-session.c
+++ libsoup/soup-session.c
@@ -3899,7 +3899,7 @@ idle_return_from_cache_cb (gpointer data)
 		return FALSE;
 	}
 
-	istream = g_object_steal_data (G_OBJECT (task), "SoupSession:istream");
+	istream = g_object_get_data (G_OBJECT (task), "SoupSession:istream");
 	async_return_from_cache (item, istream);
 
 	return FALSE;
--
cgit v0.9.1
