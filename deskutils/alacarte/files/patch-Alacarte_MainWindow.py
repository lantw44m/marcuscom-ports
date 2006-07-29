--- alacarte/MainWindow.py.orig	Sat Jul 29 13:45:31 2006
+++ alacarte/MainWindow.py	Sat Jul 29 13:45:57 2006
@@ -67,8 +67,8 @@ class MainWindow:
 
 	def run(self):
 		self.loadMenus()
-		self.editor.applications.tree.add_monitor(self.menuChanged)
-		self.editor.settings.tree.add_monitor(self.menuChanged)
+		self.editor.applications.tree.add_monitor(self.menuChanged, None)
+		self.editor.settings.tree.add_monitor(self.menuChanged, None)
 		self.tree.get_widget('mainwindow').show_all()
 		gtk.main()
 
