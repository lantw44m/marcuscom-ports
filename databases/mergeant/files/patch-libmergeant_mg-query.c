--- libmergeant/mg-query.c.orig	Thu Aug 12 22:26:44 2004
+++ libmergeant/mg-query.c	Thu Aug 12 22:27:41 2004
@@ -5117,9 +5117,11 @@
 				if (!cond)
 					has_error = TRUE;
 				else {
+					MgQfield *field_left;
+					MgQfield *field_right;
 					g_assert (mg_condition_get_cond_type (cond) == MG_CONDITION_LEAF_EQUAL);
-					MgQfield *field_left = mg_condition_leaf_get_operator (cond, MG_CONDITION_OP_LEFT);
-					MgQfield *field_right = mg_condition_leaf_get_operator (cond, MG_CONDITION_OP_RIGHT);
+					field_left = mg_condition_leaf_get_operator (cond, MG_CONDITION_OP_LEFT);
+					field_right = mg_condition_leaf_get_operator (cond, MG_CONDITION_OP_RIGHT);
 
 					if (IS_MG_QF_FIELD (field_left)) {
 						g_object_set (G_OBJECT (field_left), "value_provider", field_right, NULL);
