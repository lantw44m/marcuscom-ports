--- Alacarte/util.py.orig	Fri Jul 28 17:10:40 2006
+++ Alacarte/util.py	Fri Jul 28 17:15:42 2006
@@ -138,7 +138,7 @@ def getItemPath(file_id):
 			file_path = os.path.join(system_path, 'applications', file_id)
 			if os.path.isfile(file_path):
 				return file_path
-	file_path = os.path.join('/', 'usr', 'share', 'applications', file_id)
+	file_path = os.path.join('/', '/usr/local', 'share', 'gnome', 'applications', file_id)
 	if os.path.isfile(file_path):
 		return file_path
 	return False
@@ -163,7 +163,7 @@ def getDirectoryPath(file_id):
 			file_path = os.path.join(system_path, 'desktop-directories', file_id)
 			if os.path.isfile(file_path):
 				return file_path
-	file_path = os.path.join('/', 'usr', 'share', 'desktop-directories', file_id)
+	file_path = os.path.join('/', '/usr/local', 'share', 'gnome', 'desktop-directories', file_id)
 	if os.path.isfile(file_path):
 		return file_path
 	return False
@@ -183,7 +183,7 @@ def getSystemMenuPath(file_name):
 		for system_path in os.environ['XDG_CONFIG_DIRS'].split(':'):
 			if os.path.isfile(os.path.join(system_path, 'menus', file_name)):
 				return os.path.join(system_path, file_name)
-	file_path = os.path.join('/', 'etc', 'xdg', 'menus', file_name)
+	file_path = os.path.join('/', '/usr/local', 'etc', 'xdg', 'menus', file_name)
 	if os.path.isfile(file_path):
 		return file_path
 	return False
