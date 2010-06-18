From 512115f80f4e8a48a60ac90eb1cb478358a66c52 Mon Sep 17 00:00:00 2001
From: Benjamin Berg <benjamin@sipsolutions.net>
Date: Sun, 13 Jun 2010 18:06:41 +0000
Subject: Remove usage of GtkProgress.

---
diff --git a/engines/clearlooks/src/clearlooks_style.c b/engines/clearlooks/src/clearlooks_style.c
index 1f9a26c..7d2189a 100644
--- engines/clearlooks/src/clearlooks_style.c
+++ engines/clearlooks/src/clearlooks_style.c
@@ -802,7 +802,7 @@ clearlooks_style_draw_box (DRAW_ARGS)
 #ifdef HAVE_WORKING_ANIMATION
 		if(clearlooks_style->animation && CL_IS_PROGRESS_BAR (widget))
 		{
-			gboolean activity_mode = GTK_PROGRESS (widget)->activity_mode;
+			gboolean activity_mode = GTK_PROGRESS_BAR (widget)->activity_mode;
 
 			if (!activity_mode)
 				clearlooks_animation_progressbar_add ((gpointer)widget);
@@ -817,12 +817,8 @@ clearlooks_style_draw_box (DRAW_ARGS)
 		{
 			progressbar.orientation = gtk_progress_bar_get_orientation (GTK_PROGRESS_BAR (widget));
 			progressbar.value = gtk_progress_bar_get_fraction(GTK_PROGRESS_BAR(widget));
-#ifndef GTK_DISABLE_DEPRECATED
-			progressbar.pulsing = GTK_PROGRESS (widget)->activity_mode;
-#else
-#warning Assuming non-pulsing progress bars because GTK_DISABLE_DEPRECATED is enabled.
+#warning Assuming non-pulsing progress bars because there is currently no way to query them in GTK+ 3.0.
 			progressbar.pulsing = FALSE;
-#endif
 		}
 		else
 		{
diff --git a/themes/Clearlooks/gtk-3.0/gtkrc-common b/themes/Clearlooks/gtk-3.0/gtkrc-common
index 8a8418a..6c29269 100644
--- themes/Clearlooks/gtk-3.0/gtkrc-common
+++ themes/Clearlooks/gtk-3.0/gtkrc-common
@@ -373,7 +373,7 @@ widget_class "*<GtkSeparatorMenuItem>*" style "separator_menu_item"
 widget_class "*.<GtkFrame>.<GtkLabel>" style "frame_title"
 widget_class "*.<GtkTreeView>*" style "treeview"
 
-widget_class "*<GtkProgress>" style "progressbar"
+widget_class "*<GtkProgressBar>" style "progressbar"
 
 # Treeview headers (and similar stock GTK+ widgets)
 widget_class "*.<GtkTreeView>.<GtkButton>" style "treeview_header"
diff --git a/themes/GNOME3/gtk-3.0/gtkrc b/themes/GNOME3/gtk-3.0/gtkrc
index 47c37b7..12f3b7e 100644
--- themes/GNOME3/gtk-3.0/gtkrc
+++ themes/GNOME3/gtk-3.0/gtkrc
@@ -532,7 +532,7 @@ widget_class "*<GtkSeparatorToolItem>*" style "separator_tool_item"
 widget_class "*.<GtkFrame>.<GtkLabel>" style "frame_title"
 widget_class "*.<GtkTreeView>*" style "treeview"
 
-widget_class "*<GtkProgress>" style "progressbar"
+widget_class "*<GtkProgressBar>" style "progressbar"
 
 # Treeview headers (and similar stock GTK+ widgets)
 widget_class "*.<GtkTreeView>.<GtkButton>" style "treeview_header"
diff --git a/themes/Industrial/gtk-3.0/gtkrc b/themes/Industrial/gtk-3.0/gtkrc
index f172572..e62b26e 100644
--- themes/Industrial/gtk-3.0/gtkrc
+++ themes/Industrial/gtk-3.0/gtkrc
@@ -252,7 +252,7 @@ widget_class "*.<ETable>.*"              style "industrial-tree-header"
 # menuitems and interior
 widget_class "*<GtkMenuItem>*" style "industrial-menuitem"
 
-widget_class "*.<GtkProgress>"   style "industrial-progress"
+widget_class "*.<GtkProgressBar>"   style "industrial-progress"
 
 # druide
 widget_class "*GnomeDruidPage*" style "industrial-druid"
--
cgit v0.8.3.1
