--- libgda/gda-tree-manager.h.orig	2010-09-01 13:08:34.000000000 +0200
+++ libgda/gda-tree-manager.h	2010-09-01 13:09:52.000000000 +0200
@@ -62,7 +62,9 @@ struct _GdaTreeManagerClass {
 	 *
 	 * Returns: NULL if an error occurred, and @out_error is set to TRUE
 	 */
-	GdaTreeManagerNodesFunc update_children;
+	GSList *(*update_children) (GdaTreeManager *manager, GdaTreeNode *node,
+				const GSList *children_nodes,
+				gboolean *out_error, GError **error);
 
 
 	/*< private >*/
