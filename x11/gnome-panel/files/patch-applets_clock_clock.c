--- applets/clock/clock.c.orig	Mon Oct 24 02:25:11 2005
+++ applets/clock/clock.c	Tue Nov 22 02:47:05 2005
@@ -47,7 +47,9 @@
 #include <dirent.h>
 #include <string.h>
 #include <time.h>
+#ifdef HAVE_LANGINFO_H
 #include <langinfo.h>
+#endif
 
 #include <panel-applet.h>
 #include <panel-applet-gconf.h>
@@ -545,7 +547,11 @@ clock_locale_format (void)
 {
         const char *am;
 
+#ifdef HAVE_LANGINFO_H
         am = nl_langinfo (AM_STR);
+#else
+	am = "AM";
+#endif
         return (am[0] == '\0') ? CLOCK_FORMAT_24 : CLOCK_FORMAT_12;
 }
 
@@ -1319,7 +1325,7 @@ add_appointments_and_tasks (ClockData *c
         update_frame_visibility (cd->appointment_list, GTK_TREE_MODEL (cd->appointments_model));
 
         switch (cd->orient) {
-        case PANEL_APPLET_ORIENT_DOWN:
+	case PANEL_APPLET_ORIENT_UP:
                 gtk_box_pack_start (GTK_BOX (vbox), cd->appointment_list, TRUE, TRUE, 0);
                 gtk_box_pack_start (GTK_BOX (vbox), cd->task_list, TRUE, TRUE, 0);
                 break;
@@ -1409,7 +1415,7 @@ create_calendar (ClockData *cd,
         gtk_calendar_select_day (GTK_CALENDAR (cd->calendar), tm->tm_mday);
 
 	switch (cd->orient) {
-        case PANEL_APPLET_ORIENT_DOWN:
+	case PANEL_APPLET_ORIENT_UP:
                 add_appointments_and_tasks (cd, vbox);
                 gtk_box_pack_start (GTK_BOX (vbox), cd->calendar, TRUE, FALSE, 0);
                 break;
@@ -1498,7 +1504,7 @@ position_calendar_popup (ClockData *cd,
 			gravity = GDK_GRAVITY_NORTH_EAST;
 
 		break;
-	case PANEL_APPLET_ORIENT_UP:
+	case PANEL_APPLET_ORIENT_DOWN:
 		y += button_h;
 		if ((x + w) > monitor.x + monitor.width)
 			x -= (x + w) - (monitor.x + monitor.width);
@@ -1506,7 +1512,7 @@ position_calendar_popup (ClockData *cd,
 		gravity = GDK_GRAVITY_NORTH_WEST;
 
 		break;
-	case PANEL_APPLET_ORIENT_DOWN:
+	case PANEL_APPLET_ORIENT_UP:
 		y -= h;
 		if ((x + w) > monitor.x + monitor.width)
 			x -= (x + w) - (monitor.x + monitor.width);
@@ -1657,9 +1663,9 @@ create_clock_widget (ClockData *cd)
 	cd->orient = panel_applet_get_orient (PANEL_APPLET (cd->applet));
 
 	/* Initialize label orientation */
-	if (cd->orient == PANEL_APPLET_ORIENT_LEFT)
+	if (cd->orient == PANEL_APPLET_ORIENT_RIGHT)
 		gtk_label_set_angle (GTK_LABEL (cd->clockw), 90);
-	else if (cd->orient == PANEL_APPLET_ORIENT_RIGHT)
+	else if (cd->orient == PANEL_APPLET_ORIENT_LEFT)
 		gtk_label_set_angle (GTK_LABEL (cd->clockw), 270);
 	else
 		gtk_label_set_angle (GTK_LABEL (cd->clockw), 0);
@@ -1686,9 +1692,9 @@ applet_change_orient (PanelApplet       
 {
         cd->orient = orient;
         
-        if (cd->orient == PANEL_APPLET_ORIENT_LEFT)
+	if (cd->orient == PANEL_APPLET_ORIENT_RIGHT)
                 gtk_label_set_angle (GTK_LABEL (cd->clockw), 90);
-        else if (cd->orient == PANEL_APPLET_ORIENT_RIGHT)
+	else if (cd->orient == PANEL_APPLET_ORIENT_LEFT)
                 gtk_label_set_angle (GTK_LABEL (cd->clockw), 270);
         else
                 gtk_label_set_angle (GTK_LABEL (cd->clockw), 0);
