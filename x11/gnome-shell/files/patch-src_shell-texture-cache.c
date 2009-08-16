--- src/shell-texture-cache.c
+++ src/shell-texture-cache.c
@@ -1,7 +1,8 @@
 #include "shell-texture-cache.h"
 #include "shell-global.h"
 #include <gtk/gtk.h>
-#include <libgnomeui/gnome-thumbnail.h>
+#define GNOME_DESKTOP_USE_UNSTABLE_API
+#include <libgnomeui/gnome-desktop-thumbnail.h>
 #include <string.h>
 
 typedef struct
@@ -20,7 +21,7 @@ typedef struct
 struct _ShellTextureCachePrivate
 {
   GHashTable *keyed_cache; /* CacheKey -> CoglTexture* */
-  GnomeThumbnailFactory *thumbnails;
+  GnomeDesktopThumbnailFactory *thumbnails;
 };
 
 static void shell_texture_cache_dispose (GObject *object);
@@ -129,7 +130,7 @@ shell_texture_cache_init (ShellTextureCache *self)
   self->priv = g_new0 (ShellTextureCachePrivate, 1);
   self->priv->keyed_cache = g_hash_table_new_full (cache_key_hash, cache_key_equal,
                                                    cache_key_destroy, cogl_handle_unref);
-  self->priv->thumbnails = gnome_thumbnail_factory_new (GNOME_THUMBNAIL_SIZE_NORMAL);
+  self->priv->thumbnails = gnome_desktop_thumbnail_factory_new (GNOME_DESKTOP_THUMBNAIL_SIZE_NORMAL);
 }
 
 static void
@@ -403,7 +404,7 @@ impl_load_thumbnail (ShellTextureCache *cache,
                      guint              size,
                      GError           **error)
 {
-  GnomeThumbnailFactory *thumbnail_factory;
+  GnomeDesktopThumbnailFactory *thumbnail_factory;
   GdkPixbuf *pixbuf = NULL;
   GFile *file;
   GFileInfo *file_info;
@@ -423,24 +424,24 @@ impl_load_thumbnail (ShellTextureCache *cache,
 
   thumbnail_factory = cache->priv->thumbnails;
 
-  existing_thumbnail = gnome_thumbnail_factory_lookup (thumbnail_factory, uri, mtime);
+  existing_thumbnail = gnome_desktop_thumbnail_factory_lookup (thumbnail_factory, uri, mtime);
 
   if (existing_thumbnail != NULL)
     pixbuf = gdk_pixbuf_new_from_file_at_size (existing_thumbnail, size, size, error);
-  else if (gnome_thumbnail_factory_has_valid_failed_thumbnail (thumbnail_factory, uri, mtime))
+  else if (gnome_desktop_thumbnail_factory_has_valid_failed_thumbnail (thumbnail_factory, uri, mtime))
     g_set_error (error, G_IO_ERROR, G_IO_ERROR_FAILED, "Has failed thumbnail");
-  else if (gnome_thumbnail_factory_can_thumbnail (thumbnail_factory, uri, mime_type, mtime))
+  else if (gnome_desktop_thumbnail_factory_can_thumbnail (thumbnail_factory, uri, mime_type, mtime))
     {
-      pixbuf = gnome_thumbnail_factory_generate_thumbnail (thumbnail_factory, uri, mime_type);
+      pixbuf = gnome_desktop_thumbnail_factory_generate_thumbnail (thumbnail_factory, uri, mime_type);
       if (pixbuf)
         {
           // we need to save the thumbnail so that we don't need to generate it again in the future
-          gnome_thumbnail_factory_save_thumbnail (thumbnail_factory, pixbuf, uri, mtime);
+          gnome_desktop_thumbnail_factory_save_thumbnail (thumbnail_factory, pixbuf, uri, mtime);
         }
       else
         {
           g_set_error (error, G_IO_ERROR, G_IO_ERROR_FAILED, "Failed to generate thumbnail");
-          gnome_thumbnail_factory_create_failed_thumbnail (thumbnail_factory, uri, mtime);
+          gnome_desktop_thumbnail_factory_create_failed_thumbnail (thumbnail_factory, uri, mtime);
         }
      }
    return pixbuf;
