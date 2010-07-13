From 11b878da83dea57fce27699843c377d86e3c4a98 Mon Sep 17 00:00:00 2001
From: Johan Dahlin <johan@gnome.org>
Date: Tue, 22 Jun 2010 10:20:53 -0300
Subject: [PATCH] [gstpad] Add annotations for GstPadIntLinkFunction

https://bugzilla.gnome.org/show_bug.cgi?id=622025
---
 common       |    2 +-
 gst/gstpad.h |    2 +-
 2 files changed, 2 insertions(+), 2 deletions(-)

diff --git a/gst/gstpad.h b/gst/gstpad.h
index 56e4320..e953322 100644
--- gst/gstpad.h
+++ gst/gstpad.h
@@ -345,7 +345,7 @@ typedef gboolean		(*GstPadCheckGetRangeFunction)	(GstPad *pad);
  *
  * The signature of the internal pad link function.
  *
- * Returns: a newly allocated #GList of pads that are linked to the given pad on
+ * Returns: (element-type Gst.Pad) (transfer container): a newly allocated #GList of pads that are linked to the given pad on
  * the inside of the parent element.
  *
  * The caller must call g_list_free() on it after use.
-- 
1.6.6.1
