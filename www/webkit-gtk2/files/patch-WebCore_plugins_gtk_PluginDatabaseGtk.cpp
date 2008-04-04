--- WebCore/plugins/gtk/PluginDatabaseGtk.cpp.orig	2008-04-03 19:24:32.000000000 -0400
+++ WebCore/plugins/gtk/PluginDatabaseGtk.cpp	2008-04-04 10:45:21.455604357 -0400
@@ -78,7 +78,7 @@
     directory = g_build_filename(G_DIR_SEPARATOR_S "usr", "lib", "browser", "plugins", 0);
     directories.append(directory);
     g_free(directory);
-    directory = g_build_filename(G_DIR_SEPARATOR_S "usr", "local", "lib", "mozilla", "plugins", 0);
+    directory = g_build_filename(G_DIR_SEPARATOR_S %%_BROWSER_PLUGINS_DIR%% 0);
     directories.append(directory);
     g_free (directory);
     directory = g_build_filename(G_DIR_SEPARATOR_S "usr", "lib", "mozilla", "plugins", 0);
