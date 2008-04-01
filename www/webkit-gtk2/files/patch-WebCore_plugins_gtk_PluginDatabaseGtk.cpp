--- WebCore/plugins/gtk/PluginDatabaseGtk.cpp.orig	2008-04-01 11:14:13.073176655 -0400
+++ WebCore/plugins/gtk/PluginDatabaseGtk.cpp	2008-04-01 11:15:02.191591705 -0400
@@ -80,7 +80,7 @@
         g_strfreev(pluginPaths);
     }
 
-    path = g_build_filename(G_DIR_SEPARATOR_S "usr", "lib", "browser", "plugins", 0);
+    path = g_build_filename(G_DIR_SEPARATOR_S %%_BROWSER_PLUGINS_DIR%% 0);
     paths.append(path);
     g_free(path);
     path = g_build_filename(G_DIR_SEPARATOR_S "usr", "local", "lib", "mozilla", "plugins", 0);
