--- blackjack/src/game.cpp.orig	Tue Jun 17 13:01:16 2003
+++ blackjack/src/game.cpp	Tue Jun 17 13:02:39 2003
@@ -98,7 +98,7 @@
 }
 
 int
-bj_is_ruleset (const struct dirent* dent)
+bj_is_ruleset (struct dirent* dent)
 {
   return (!strcmp (g_extension_pointer (dent->d_name), "rules"));
 }
