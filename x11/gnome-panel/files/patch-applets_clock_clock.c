--- applets/clock/clock.c.orig	2008-02-12 23:25:13.000000000 -0500
+++ applets/clock/clock.c	2008-02-12 23:27:56.000000000 -0500
@@ -84,6 +84,8 @@
 
 #define FALLBACK_CONFIG_TOOL "time-admin"
 
+#define daylight 1
+
 static const char *clock_config_tools [] = {
 	CLOCK_TIME_UTILITY,
 	FALLBACK_CONFIG_TOOL
@@ -2848,6 +2850,20 @@ prefs_locations_changed (GtkTreeSelectio
 	gtk_widget_set_sensitive (cd->prefs_location_remove_button, n > 0);
 }
 
+static GList *
+glist_deep_copy (GList *src)
+{
+	GList *dst;
+	GList *l;
+
+	dst = g_list_copy (src);
+	for (l = dst; l; l = l->next) {
+		l->data = g_object_ref (l->data);
+	}
+
+	return dst;
+}
+
 static gchar *
 loc_to_string (ClockLocation *loc)
 {
@@ -2954,7 +2970,7 @@ run_prefs_edit_save (GtkButton *button, 
 
                 loc = clock_location_new (name, clock_zoneinfo_get_name (info), lat, lon, weather_code, &prefs);
 
-                locs = g_list_copy (cd->locations);
+                locs = glist_deep_copy (cd->locations);
                 locs = g_list_append (locs, loc);
                 set_locations (cd, locs);
         }
@@ -3520,7 +3536,7 @@ remove_tree_row (GtkTreeModel *model, Gt
 {
         ClockData *cd = data;
         ClockLocation *loc = NULL;
-        GList *list = g_list_copy (cd->locations);
+        GList *list = glist_deep_copy (cd->locations);
 
         gtk_tree_model_get (model, iter, COL_CITY_LOC, &loc, -1);
 
