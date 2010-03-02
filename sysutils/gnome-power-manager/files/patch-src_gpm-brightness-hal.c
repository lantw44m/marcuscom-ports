--- src/gpm-brightness-hal.c.orig	2010-03-02 15:05:33.000000000 +0800
+++ src/gpm-brightness-hal.c	2010-03-02 15:06:07.000000000 +0800
@@ -441,6 +441,7 @@
 	HalDevice *device;
 	gboolean res;
 	DBusGConnection *connection;
+	GError *error = NULL;
 
 	brightness->priv = GPM_BRIGHTNESS_HAL_GET_PRIVATE (brightness);
 	brightness->priv->proxy = NULL;
