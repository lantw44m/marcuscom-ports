--- daemon/gvfsbackendcomputer.c.orig	2008-01-09 03:12:26.000000000 -0500
+++ daemon/gvfsbackendcomputer.c	2008-01-09 03:13:00.000000000 -0500
@@ -417,6 +417,7 @@ recompute_files (GVfsBackendComputer *ba
           file->icon = g_volume_get_icon (file->volume);
           file->display_name = g_volume_get_name (file->volume);
           file->can_mount = g_volume_can_mount (file->volume);
+          file->root = NULL;
           file->can_eject = g_volume_can_eject (file->volume);
         }
       else /* drive */
