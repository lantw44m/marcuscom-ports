--- calendar/backends/groupwise/e-cal-backend-groupwise.c.orig	Wed Jul 13 02:21:58 2005
+++ calendar/backends/groupwise/e-cal-backend-groupwise.c	Wed Jul 13 02:22:22 2005
@@ -365,11 +365,12 @@ get_deltas (gpointer handle)
 
 	for (; item_list != NULL; item_list = g_list_next(item_list)) {
 		EGwItem *item = NULL;
-		item = E_GW_ITEM(item_list->data);
 		ECalComponent *modified_comp = NULL, *cache_comp = NULL;
 		char *cache_comp_str = NULL;
 		const char *uid, *rid = NULL;
 		int r_key;
+
+		item = E_GW_ITEM(item_list->data);
 
 		modified_comp = e_gw_item_to_cal_component (item, cbgw);
 		if (!modified_comp) {
