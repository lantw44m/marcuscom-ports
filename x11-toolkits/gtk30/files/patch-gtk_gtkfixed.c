From 62d7593fc2961966c93912cacc8059158194949c Mon Sep 17 00:00:00 2001
From: Vincent Untz <vuntz@gnome.org>
Date: Tue, 01 Feb 2011 19:01:49 +0000
Subject: Fix crash in gtk_fixed_remove()

b3f6f67c changed the loop from while() to for(), but the line to move to
the next child was kept, so we could go past the end of the list.

https://bugzilla.gnome.org/show_bug.cgi?id=641176
---
diff --git a/gtk/gtkfixed.c b/gtk/gtkfixed.c
index e61f03a..fd92cd7 100644
--- gtk/gtkfixed.c
+++ gtk/gtkfixed.c
@@ -526,8 +526,6 @@ gtk_fixed_remove (GtkContainer *container,
 
           break;
         }
-
-      children = children->next;
     }
 }
 
--
cgit v0.8.3.1
