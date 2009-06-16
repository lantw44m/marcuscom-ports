--- plugins/housekeeping/gsd-disk-space.c.orig        2009-06-16 16:57:54.000000000 -0400
+++ plugins/housekeeping/gsd-disk-space.c        2009-06-16 17:08:33.000000000 -0400
@@ -233,6 +233,7 @@ ldsm_check_all_mounts (gpointer data)
         for (l = mounts; l != NULL; l = l->next) {
                 GUnixMountEntry *mount = l->data;
                 const char *path;
+                const char *fs_type;
 
                 if (g_unix_mount_is_readonly (mount)) {
                         g_unix_mount_free (mount);
@@ -246,6 +247,16 @@ ldsm_check_all_mounts (gpointer data)
                         continue;
                 }
 
+                fs_type = g_unix_mount_get_fs_type (mount);
+
+                if (! strcmp (fs_type, "devfs") ||
+                    ! strcmp (fs_type, "linprocfs") ||
+                    ! strcmp (fs_type, "procfs") ||
+                    ! strcmp (fs_type, "linsysfs")) {
+                        g_unix_mount_free (mount);
+                        continue;
+                }
+
                 g_hash_table_insert (seen,
                                      g_strdup (path), GINT_TO_POINTER(1));
 
