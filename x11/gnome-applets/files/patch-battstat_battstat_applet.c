--- battstat/battstat_applet.c.orig	Mon Jul 19 18:31:16 2004
+++ battstat/battstat_applet.c	Mon Jul 19 18:34:41 2004
@@ -474,7 +474,11 @@
    ) {
       /* Warn that battery dropped below red_val */
       if(battery->lowbattnotification) {
+#ifdef __FreeBSD__
+	 new_string = get_remaining (apminfo.ai_batt_time);
+#else
 	 new_string = get_remaining (apminfo.battery_time);
+#endif
 	 new_label = g_strdup_printf (_("Your battery is running low (%d%%, %s). You should recharge your battery to avoid losing your work."), batt_life, new_string);
 	 g_free (new_string);
 	 battery->lowbattnotificationdialog = gtk_dialog_new_with_buttons (
@@ -733,7 +737,11 @@
       }
       
       if (batt_state != 3)
+#ifdef __FreeBSD__
+	      rem_time = get_remaining(apminfo.ai_batt_time);
+#else
 	      rem_time = get_remaining(apminfo.battery_time);
+#endif
       else
 	      rem_time = g_strdup(_(status[batt_state]));
       
