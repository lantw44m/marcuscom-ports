--- calendar/backends/groupwise/e-cal-backend-groupwise.c.orig	Tue Jan 11 12:46:18 2005
+++ calendar/backends/groupwise/e-cal-backend-groupwise.c	Tue Jan 11 12:47:20 2005
@@ -509,7 +509,6 @@
 					priv->timeout_id = g_timeout_add (CACHE_REFRESH_INTERVAL, (GSourceFunc) get_deltas, (gpointer) cbgw);
 				} else {
 					g_warning (G_STRLOC ": Could not populate the cache");
-	ECalBackendSyncStatus status;
 					return GNOME_Evolution_Calendar_PermissionDenied;	
 				}
 			}	 
