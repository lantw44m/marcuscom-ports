--- addressbook/backends/groupwise/e-book-backend-groupwise.c.orig	Mon Apr  5 18:55:00 2004
+++ addressbook/backends/groupwise/e-book-backend-groupwise.c	Mon Apr  5 18:56:21 2004
@@ -382,10 +382,10 @@
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
@@ -466,8 +466,8 @@
 	GList *email_list;
 	EContact *contact;
 	char *email;
-	contact = E_CONTACT (data);
 	int i;
+	contact = E_CONTACT (data);
 
 	email_list = NULL;
 	for (i =0 ; i < 3; i++) {
@@ -524,9 +524,9 @@
 populate_full_name (EContact *contact, gpointer data)
 {
 	EGwItem *item;
-	item = E_GW_ITEM(data);
 	FullName  *full_name ;
 	char *full_name_string;
+	item = E_GW_ITEM(data);
 
 	full_name = e_gw_item_get_full_name (item);
 	if (full_name) {
@@ -640,8 +640,8 @@
 {
   
 	EContact *contact;
-	contact = E_CONTACT (data);
 	GList*  members ;
+	contact = E_CONTACT (data);
 	members = e_contact_get (contact, E_CONTACT_EMAIL);
 	e_gw_item_set_member_list (item, members);
   
