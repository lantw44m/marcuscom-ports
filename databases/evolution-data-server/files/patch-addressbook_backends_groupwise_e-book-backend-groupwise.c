--- addressbook/backends/groupwise/e-book-backend-groupwise.c.orig	Mon Apr 19 09:10:40 2004
+++ addressbook/backends/groupwise/e-book-backend-groupwise.c	Tue Apr 20 14:46:07 2004
@@ -384,10 +384,10 @@
 populate_birth_date (EContact *contact, gpointer data)
 {
 	EGwItem *item;
-  
-	item = E_GW_ITEM (data);
 	char *value ;
 	EContactDate *date;
+  
+	item = E_GW_ITEM (data);
 	value = e_gw_item_get_field_value (item, "birthday");
  	if (value) {
 		date =  e_contact_date_from_string (value);
@@ -468,8 +468,8 @@
 	GList *email_list;
 	EContact *contact;
 	char *email;
-	contact = E_CONTACT (data);
 	int i;
+	contact = E_CONTACT (data);
 
 	email_list = NULL;
 	for (i =0 ; i < 3; i++) {
@@ -526,9 +526,9 @@
 populate_full_name (EContact *contact, gpointer data)
 {
 	EGwItem *item;
-	item = E_GW_ITEM(data);
 	FullName  *full_name ;
 	char *full_name_string;
+	item = E_GW_ITEM(data);
 
 	full_name = e_gw_item_get_full_name (item);
 	if (full_name) {
