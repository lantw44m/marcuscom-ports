--- WebCore/plugins/gtk/PluginDatabaseGtk.cpp.orig	2008-04-18 04:00:55.000000000 -0400
+++ WebCore/plugins/gtk/PluginDatabaseGtk.cpp	2008-04-21 08:15:45.665667131 -0400
@@ -75,7 +75,7 @@
         g_strfreev(pluginPaths);
     }
 
-    directory = g_build_filename(G_DIR_SEPARATOR_S "usr", "lib", "browser", "plugins", NULL);
+    directory = g_build_filename(G_DIR_SEPARATOR_S %%_BROWSER_PLUGINS_DIR%% NULL);
     directories.append(directory);
     g_free(directory);
     directory = g_build_filename(G_DIR_SEPARATOR_S "usr", "local", "lib", "mozilla", "plugins", NULL);
