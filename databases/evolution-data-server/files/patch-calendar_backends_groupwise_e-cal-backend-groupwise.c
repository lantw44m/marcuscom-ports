--- calendar/backends/groupwise/e-cal-backend-groupwise.c.orig	Mon Jul 25 21:47:58 2005
+++ calendar/backends/groupwise/e-cal-backend-groupwise.c	Fri Jul 29 17:26:01 2005
@@ -312,12 +312,13 @@ get_deltas (gpointer handle)
 
 	for (; item_list != NULL; item_list = g_list_next(item_list)) {
 		EGwItem *item = NULL;
-		item = E_GW_ITEM(item_list->data);
 		ECalComponent *modified_comp = NULL, *cache_comp = NULL;
 		char *cache_comp_str = NULL;
 		const char *uid, *rid = NULL;
 		int r_key;
 
+		item = E_GW_ITEM(item_list->data);
+
 		modified_comp = e_gw_item_to_cal_component (item, cbgw);
 		if (!modified_comp) {
 			g_message ("Invalid component returned in update");
@@ -1048,7 +1049,7 @@ e_cal_backend_groupwise_get_static_capab
 				  CAL_STATIC_CAPABILITY_DELEGATE_TO_MANY "," \
 				  CAL_STATIC_CAPABILITY_NO_ORGANIZER "," \
 				  CAL_STATIC_CAPABILITY_RECURRENCES_NO_MASTER "," \
-				  CAL_STATIC_CAPABILITY_HAS_UNACCEPTED_MEETING "," \ 
+				  CAL_STATIC_CAPABILITY_HAS_UNACCEPTED_MEETING "," \
 				  CAL_STATIC_CAPABILITY_SAVE_SCHEDULES);
 
 	return GNOME_Evolution_Calendar_Success;
