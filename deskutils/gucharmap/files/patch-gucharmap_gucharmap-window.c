--- gucharmap/gucharmap-window.c.orig	Sat Feb  7 03:58:10 2004
+++ gucharmap/gucharmap-window.c	Sat Feb  7 03:59:36 2004
@@ -121,9 +121,9 @@
               GucharmapWindow       *guw)
 {
   GucharmapWindowPrivate *priv = GUCHARMAP_WINDOW_GET_PRIVATE (guw);
+  GdkCursor *cursor = gdk_cursor_new (GDK_WATCH);
   g_assert (IS_GUCHARMAP_WINDOW (guw));
 
-  GdkCursor *cursor = gdk_cursor_new (GDK_WATCH);
   gdk_window_set_cursor (GTK_WIDGET (guw)->window, cursor);
   gdk_cursor_unref (cursor);
 
@@ -361,8 +361,8 @@
     {
       GucharmapWindowPrivate *priv = GUCHARMAP_WINDOW_GET_PRIVATE (guw);
       gucharmap_charmap_set_chapters (guw->charmap, GUCHARMAP_CHAPTERS (gucharmap_script_chapters_new ()));
-      gtk_label_set_text (GTK_LABEL (gtk_bin_get_child (GTK_BIN (priv->next_chapter_menu_item))), _("Next Script"));;
-      gtk_label_set_text (GTK_LABEL (gtk_bin_get_child (GTK_BIN (priv->prev_chapter_menu_item))), _("Previous Script"));;
+      gtk_label_set_text (GTK_LABEL (gtk_bin_get_child (GTK_BIN (priv->next_chapter_menu_item))), _("Next Script"));
+      gtk_label_set_text (GTK_LABEL (gtk_bin_get_child (GTK_BIN (priv->prev_chapter_menu_item))), _("Previous Script"));
     }
 }
 
@@ -374,8 +374,8 @@
     {
       GucharmapWindowPrivate *priv = GUCHARMAP_WINDOW_GET_PRIVATE (guw);
       gucharmap_charmap_set_chapters (guw->charmap, GUCHARMAP_CHAPTERS (gucharmap_block_chapters_new ()));
-      gtk_label_set_text (GTK_LABEL (gtk_bin_get_child (GTK_BIN (priv->next_chapter_menu_item))), _("Next Block"));;
-      gtk_label_set_text (GTK_LABEL (gtk_bin_get_child (GTK_BIN (priv->prev_chapter_menu_item))), _("Previous Block"));;
+      gtk_label_set_text (GTK_LABEL (gtk_bin_get_child (GTK_BIN (priv->next_chapter_menu_item))), _("Next Block"));
+      gtk_label_set_text (GTK_LABEL (gtk_bin_get_child (GTK_BIN (priv->prev_chapter_menu_item))), _("Previous Block"));
     }
 }
 
@@ -778,12 +778,12 @@
   g_signal_connect (priv->status, "realize", G_CALLBACK (status_realize), guw);
 
   priv->progress = gtk_progress_bar_new ();
-  gtk_box_pack_start (GTK_BOX (hbox), priv->progress, FALSE, FALSE, 0);;
+  gtk_box_pack_start (GTK_BOX (hbox), priv->progress, FALSE, FALSE, 0);
 
 #if 0
   grip = gtk_statusbar_new ();
   gtk_statusbar_set_has_resize_grip (GTK_STATUSBAR (grip), TRUE);
-  gtk_box_pack_start (GTK_BOX (hbox), grip, FALSE, FALSE, 0);;
+  gtk_box_pack_start (GTK_BOX (hbox), grip, FALSE, FALSE, 0);
 #endif
   gtk_widget_show_all (hbox);
 
