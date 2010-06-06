From 4edc5f843a4cb0d89c21fd957dc7d6fa955cf012 Mon Sep 17 00:00:00 2001
From: Alexander Larsson <alexl@redhat.com>
Date: Tue, 01 Jun 2010 07:17:56 +0000
Subject: Don't use deprecated Gtk+ api (GtkBoxChild)

---
diff --git a/libnautilus-private/nautilus-keep-last-vertical-box.c b/libnautilus-private/nautilus-keep-last-vertical-box.c
index 8aabb56..5e350e1 100644
--- libnautilus-private/nautilus-keep-last-vertical-box.c
+++ libnautilus-private/nautilus-keep-last-vertical-box.c
@@ -84,13 +84,13 @@ nautilus_keep_last_vertical_box_new (gint spacing)
 	return GTK_WIDGET (box);
 }
 
-static void	
-nautilus_keep_last_vertical_box_size_allocate (GtkWidget *widget, 
+static void
+nautilus_keep_last_vertical_box_size_allocate (GtkWidget *widget,
 					       GtkAllocation *allocation)
 {
 	GtkBox *box;
-	GtkBoxChild *last_child, *child;
-	GList *children;
+	GtkWidget *last_child, *child;
+	GList *children, *l;
 	GtkAllocation last_child_allocation, child_allocation, tiny_allocation;
 
 	g_return_if_fail (NAUTILUS_IS_KEEP_LAST_VERTICAL_BOX (widget));
@@ -99,13 +99,14 @@ nautilus_keep_last_vertical_box_size_allocate (GtkWidget *widget,
 	EEL_CALL_PARENT (GTK_WIDGET_CLASS, size_allocate, (widget, allocation));
 
 	box = GTK_BOX (widget);
-	children = g_list_last (box->children);
+	children = gtk_container_get_children (GTK_CONTAINER(widget));
+	l = g_list_last (children);
 
-	if (children != NULL) {
-		last_child = children->data;
-		children = children->prev;
+	if (l != NULL) {
+		last_child = l->data;
+		l = l->prev;
 
-		last_child_allocation = last_child->widget->allocation;
+		gtk_widget_get_allocation (last_child, &last_child_allocation);
 
 		/* If last child doesn't fit vertically, prune items from the end of the
 		 * list one at a time until it does.
@@ -113,11 +114,11 @@ nautilus_keep_last_vertical_box_size_allocate (GtkWidget *widget,
 		if (last_child_allocation.y + last_child_allocation.height >
 		    allocation->y + allocation->height) {
 
-			while (children != NULL) {
-				child = children->data;
-				children = children->prev;
+			while (l != NULL) {
+				child = l->data;
+				l = l->prev;
 
-				child_allocation = child->widget->allocation;
+				gtk_widget_get_allocation (child, &child_allocation);
 
 				/* Reallocate this child's position so that it does not appear.
 				 * Setting the width & height to 0 is not enough, as
@@ -126,20 +127,20 @@ nautilus_keep_last_vertical_box_size_allocate (GtkWidget *widget,
 				 * This might not work in all future cases. Alternatively, the
 				 * items that don't fit could be hidden, but that would interfere
 				 * with having other hidden children.
-				 * 
+				 *
 				 * Note that these children are having their size allocated twice,
 				 * once by gtk_vbox_size_allocate and then again here. I don't
 				 * know of any problems with this, but holler if you do.
 				 */
 				tiny_allocation.x = tiny_allocation.y = -1;
 				tiny_allocation.height = tiny_allocation.width = 0;
-				gtk_widget_size_allocate (child->widget, &tiny_allocation);
+				gtk_widget_size_allocate (child, &tiny_allocation);
 
 				/* We're done if the special last item fits now. */
 				if (child_allocation.y + last_child_allocation.height <=
 				    allocation->y + allocation->height) {
 					last_child_allocation.y = child_allocation.y;
-					gtk_widget_size_allocate (last_child->widget, &last_child_allocation);
+					gtk_widget_size_allocate (last_child, &last_child_allocation);
 					break;
 				}
 
@@ -148,12 +149,13 @@ nautilus_keep_last_vertical_box_size_allocate (GtkWidget *widget,
 				 * just too darn tall. Let's squash it down to fit in the box's
 				 * allocation.
 				 */
-				if (children == NULL) {
+				if (l == NULL) {
 					last_child_allocation.y = allocation->y;
 					last_child_allocation.height = allocation->height;
-					gtk_widget_size_allocate (last_child->widget, &last_child_allocation);
+					gtk_widget_size_allocate (last_child, &last_child_allocation);
 				}
 			}
 		}
 	}
-}		       			      
+	g_list_free (children);
+}
--
cgit v0.8.3.1
