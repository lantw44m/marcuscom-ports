--- src/interface.c.orig	Fri Dec 12 02:22:50 2003
+++ src/interface.c	Fri Dec 12 02:23:05 2003
@@ -395,6 +395,7 @@
 	sizegroup = gtk_size_group_new (GTK_SIZE_GROUP_HORIZONTAL);
 	for (i=0;i<procdata->config.num_cpus; i++) {
 		GtkWidget *temp_hbox;
+		gchar *text;
 		/* Two per row */
 		if (fabs(fmod(i,2) - 0) < .01) {
 			hbox = gtk_hbox_new (FALSE, 12);
@@ -416,7 +417,7 @@
 			    G_CALLBACK (cb_cpu_color_changed), GINT_TO_POINTER (i));
 		gtk_box_pack_start (GTK_BOX (temp_hbox), color_picker, FALSE, FALSE, 0);
 		
-		gchar *text = g_strdup_printf (_("CPU%d:"), i+1);
+		text = g_strdup_printf (_("CPU%d:"), i+1);
 		label = gtk_label_new (text);
 		gtk_box_pack_start (GTK_BOX (temp_hbox), label, FALSE, FALSE, 0);
 		g_free (text);
