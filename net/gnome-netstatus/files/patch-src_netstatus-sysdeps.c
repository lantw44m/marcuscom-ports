--- src/netstatus-sysdeps.c.orig	Tue Mar 30 04:25:42 2004
+++ src/netstatus-sysdeps.c	Thu Jun 10 13:29:42 2004
@@ -35,6 +35,16 @@
 #include <glib.h>
 #include <libgnome/gnome-i18n.h>
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/ioctl.h>
+#include <net/if.h>
+#include <net/if_var.h>
+#include <dev/an/if_aironet_ieee.h>
+#include <dev/wi/if_wavelan_ieee.h>
+#endif
+
 static inline gboolean
 parse_stats (char  *buf,
 	     int    prx_idx,
@@ -385,6 +395,131 @@
      }
 }
 
+static inline gboolean
+wireless_getval (const char    *iface,
+		 gpointer       req,
+		 unsigned long  req_type,
+		 char          **error)
+{
+  struct ifreq ifr;
+  int s;
+
+  memcpy ((char *) &ifr, 0, sizeof (ifr));
+
+  strlcpy (ifr.ifr_name, iface, sizeof (ifr.ifr_name));
+  ifr.ifr_data = (caddr_t) req;
+
+  s = socket (AF_INET, SOCK_DGRAM, 0);
+
+  if (s == -1) {
+    *error = g_strdup_printf (_("Could not connect to interface, '%s'"), iface);
+    return FALSE;
+  }
+
+  if (ioctl (s, req_type, &ifr) == -1) {
+    *error = g_strdup_printf (_("Could not send ioctl to interface, '%s'"), iface);
+    close (s);
+    return FALSE;
+  }
+
+  close (s);
+  return TRUE;
+}
+
+static inline char*
+get_an_data (const char *iface,
+	     int        *signal_strength)
+{
+  struct an_req areq;
+  struct an_ltv_status *sts;
+#ifdef AN_RID_RSSI_MAP
+  struct an_ltv_rssi_map an_rssimap;
+#endif
+  int level;
+  char *error = NULL;
+  gboolean rssimap_valid = FALSE;
+
+#ifdef AN_RID_RSSI_MAP
+  an_rssimap.an_len = sizeof (an_rssimap);
+  an_rssimap.an_type = AN_RID_RSSI_MAP;
+  rssimap_valid = wireless_getval (iface, (gpointer) &an_rssimap, SIOCGAIRONET, &error);
+#endif
+
+  areq.an_len = sizeof (areq);
+  areq.an_type = AN_RID_STATUS;
+
+  if (!wireless_getval (iface, (gpointer) &areq, SIOCGAIRONET, &error))
+    return error;
+
+  sts = (struct an_ltv_status *)&areq;
+#ifdef AN_RID_RSSI_MAP
+  if (rssimap_valid)
+    level = (int) (an_rssimap.an_entries[sts->an_normalized_strength].an_rss_pct);
+  else
+    level = (int) (sts->an_normalized_strength);
+#else
+  level = (int) (sts->an_normalized_rssi);
+#endif
+  memcpy (signal_strength, &level, sizeof (signal_strength));
+
+  return error;
+}
+
+static inline char*
+get_wi_data (const char *iface,
+	     int        *signal_strength)
+{
+  struct wi_req wreq;
+  int level;
+  char *error = NULL;
+
+  memcpy ((char *) &wreq, 0, sizeof (wreq));
+
+  wreq.wi_len  = WI_MAX_DATALEN;
+  wreq.wi_type = WI_RID_COMMS_QUALITY;
+
+  if (!wireless_getval (iface, (gpointer) &wreq, SIOCGWAVELAN, &error))
+    return error;
+
+  level = (int) (wreq.wi_val[1]);
+
+  memcpy (signal_strength, &level, sizeof (signal_strength));
+
+  return error;
+}
+
+char *
+netstatus_sysdeps_read_iface_wireless_details (const char *iface,
+					       gboolean   *is_wireless,
+					       int        *signal_strength)
+{
+  char *error_message = NULL;
+
+  g_return_val_if_fail (iface != NULL, NULL);
+  g_return_val_if_fail (is_wireless != NULL, NULL);
+  g_return_val_if_fail (signal_strength != NULL, NULL);
+
+  if (is_wireless)
+    *is_wireless = FALSE;
+  if (signal_strength)
+    *signal_strength = 0;
+
+  if (g_strncasecmp (iface, "an", 2) && g_strncasecmp (iface, "wi", 2) &&
+    g_strncasecmp (iface, "ath", 3))
+    return error_message;
+
+  if (g_strncasecmp (iface, "an", 2) == 0) {
+    error_message = get_an_data (iface, signal_strength);
+    *is_wireless = TRUE;
+  }
+  else {
+    error_message = get_wi_data (iface, signal_strength);
+    *is_wireless = TRUE;
+  }
+
+  return error_message;
+}
+
 char *
 netstatus_sysdeps_read_iface_statistics (const char *iface,
 					 long       *in_packets,
@@ -486,23 +621,6 @@
   g_strfreev (argv);
 
   return error_message;
-}
-
-char *
-netstatus_sysdeps_read_iface_wireless_details (const char *iface,
-					       gboolean   *is_wireless,
-					       int        *signal_strength)
-{
-  g_return_val_if_fail (iface != NULL, NULL);
-  g_return_val_if_fail (is_wireless != NULL, NULL);
-  g_return_val_if_fail (signal_strength_wireless != NULL, NULL);
-
-  if (is_wireless)
-    *is_wireless = FALSE;
-  if (signal_strength)
-    *signal_strength = 0;
-
-  return NULL;
 }
 
 #endif /* !defined(__FreeBSD__) */
