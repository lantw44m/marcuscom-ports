--- deskbar/ui/cuemiac/CuemiacPopupEntry.py.orig	Thu Jun 15 13:47:05 2006
+++ deskbar/ui/cuemiac/CuemiacPopupEntry.py	Thu Jun 15 13:47:17 2006
@@ -115,11 +115,12 @@ class CuemiacPopupEntry (CuemiacLayoutPr
 				print "WARNING in CuemiacEntryPopup : No toplevel window for entry!"
 				return
 
+		self.popup_window.update_position()
+		self.popup_window.show_all()
+
 		self.view.realize()
 		self.selection.unselect_all()
 		
-		self.popup_window.update_position()
-		self.popup_window.show_all ()
 		self.view.grab_focus()
 
 		# Grab pointer
