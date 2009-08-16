From 557f9ceb97bde57fa3715c4a91cfd4982f3402d1 Mon Sep 17 00:00:00 2001
From: Colin Walters <walters@verbum.org>
Date: Thu, 13 Aug 2009 15:31:53 +0000
Subject: Bug 591590 - Fix some applications not appearing in menu

Use the correct address for the entry, instead of treating the
ShellAppInfo pointer as one.
---
diff --git a/src/shell-app-system.c b/src/shell-app-system.c
index d415f18..d4ee4cb 100644
--- src/shell-app-system.c
+++ src/shell-app-system.c
@@ -848,7 +848,7 @@ shell_app_info_get_is_nodisplay (ShellAppInfo *info)
   switch (info->type)
   {
     case SHELL_APP_INFO_TYPE_ENTRY:
-      return gmenu_tree_entry_get_is_nodisplay ((GMenuTreeEntry*)info);
+      return gmenu_tree_entry_get_is_nodisplay ((GMenuTreeEntry*)info->entry);
     case SHELL_APP_INFO_TYPE_DESKTOP_FILE:
       return FALSE;
   }
