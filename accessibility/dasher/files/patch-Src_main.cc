--- Src/main.cc.orig	Fri Feb 17 18:32:50 2006
+++ Src/main.cc	Fri Feb 17 18:33:12 2006
@@ -229,7 +229,7 @@ int main(int argc, char *argv[]) {
 #endif
 
 #ifndef WITH_MAEMO
-  gtk_window_set_icon_from_file(GTK_WINDOW(window), DATADIR "/icons/hicolor/48x48/apps/dasher.png", NULL);
+  gtk_window_set_icon_from_file(GTK_WINDOW(window), PREFIX "/share/icons/hicolor/48x48/apps/dasher.png", NULL);
   gtk_widget_show(window);
 #else
   appview = HILDON_APPVIEW( hildon_appview_new(NULL) );
