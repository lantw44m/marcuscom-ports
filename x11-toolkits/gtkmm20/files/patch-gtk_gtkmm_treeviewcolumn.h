--- gtk/gtkmm/treeviewcolumn.h.orig	Thu Dec  4 23:35:40 2003
+++ gtk/gtkmm/treeviewcolumn.h	Thu Dec  4 23:37:23 2003
@@ -343,7 +343,7 @@
 void TreeViewColumn::pack_start(const TreeModelColumn<T_ModelColumnType>& column, bool expand)
 {
   //Generate appropriate Renderer for the column:
-  CellRenderer* pCellRenderer = manage( CellRenderer_Generation::generate_cellrenderer<T_ModelColumnType>() );
+  CellRenderer* pCellRenderer = manage( CellRenderer_Generation::generate_cellrenderer<T_ModelColumnType>(false) );
 
   //Use the renderer:
   pack_start(*pCellRenderer, expand);
@@ -354,7 +354,7 @@
 void TreeViewColumn::pack_end(const TreeModelColumn<T_ModelColumnType>& column, bool expand)
 {
   //Generate appropriate Renderer for the column:
-  CellRenderer* pCellRenderer= manage( CellRenderer_Generation::generate_cellrenderer<T_ModelColumnType>() );
+  CellRenderer* pCellRenderer= manage( CellRenderer_Generation::generate_cellrenderer<T_ModelColumnType>(false) );
 
   //Use the renderer:
   pack_end(*pCellRenderer, expand);
