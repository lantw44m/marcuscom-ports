--- src/commands.c.orig	Sat Sep  4 16:07:54 2004
+++ src/commands.c	Sat Sep  4 16:09:28 2004
@@ -3634,6 +3634,11 @@
 } CmdMergeCells;
 
 static void
+cmd_merge_cells_repeat (GnmCommand const *cmd, WorkbookControl *wbc);
+
+MAKE_GNM_COMMAND (CmdMergeCells, cmd_merge_cells, cmd_merge_cells_repeat);
+
+static void
 cmd_merge_cells_repeat (GnmCommand const *cmd, WorkbookControl *wbc)
 {
 	SheetView *sv = wb_control_cur_sheet_view (wbc);
@@ -3642,7 +3647,6 @@
 		CMD_MERGE_CELLS (cmd)->center);
 	range_fragment_free (range_list);
 }
-MAKE_GNM_COMMAND (CmdMergeCells, cmd_merge_cells, cmd_merge_cells_repeat);
 
 static gboolean
 cmd_merge_cells_undo (GnmCommand *cmd, WorkbookControl *wbc)
