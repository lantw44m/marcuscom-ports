--- gnomemusic/view.py	2014-05-31 11:19:51.201606678 +0000
+++ gnomemusic/view.py.orig	2014-05-31 11:19:51.157607277 +0000
@@ -372,17 +372,11 @@
 
     @log
     def _on_changes_pending(self, data=None):
-        if (self._init and self.header_bar._selectionMode is False):
+        if (self._init):
             self._offset = 0
             self._cached_count = -1
             self._model.clear()
             self.populate()
-            grilo.changes_pending['Albums'] = False
-
-    @log
-    def _on_selection_mode_changed(self, widget, data=None):
-        if self.header_bar._selectionMode is False and grilo.changes_pending['Albums'] is True:
-            self._on_changes_pending()
 
     @log
     def _back_button_clicked(self, widget, data=None):
@@ -465,17 +459,11 @@
 
     @log
     def _on_changes_pending(self, data=None):
-        if (self._init and self.header_bar._selectionMode is False):
+        if (self._init):
             self._model.clear()
             self._offset = 0
             self._cached_count = -1
             self.populate()
-            grilo.changes_pending['Songs'] = False
-
-    @log
-    def _on_selection_mode_changed(self, widget, data=None):
-        if self.header_bar._selectionMode is False and grilo.changes_pending['Songs'] is True:
-            self._on_changes_pending()
 
     @log
     def _on_item_activated(self, widget, id, path):
@@ -658,13 +646,12 @@
 
     @log
     def _on_changes_pending(self, data=None):
-        if (self._init and self.header_bar._selectionMode is False):
+        if (self._init):
             self._model.clear()
             self._artists.clear()
             self._offset = 0
             self._cached_count = -1
             self._populate()
-            grilo.changes_pending['Artists'] = False
 
     @log
     def _populate(self, data=None):
@@ -776,12 +763,6 @@
                     self._last_selection)
 
     @log
-    def _on_selection_mode_changed(self, widget, data=None):
-        self.artistAlbumsStack.set_sensitive(not self.header_bar._selectionMode)
-        if self.header_bar._selectionMode is False and grilo.changes_pending['Artists'] is True:
-            self._on_changes_pending()
-
-    @log
     def get_selected_track_uris(self, callback):
         self.items_selected = []
         self.items_selected_callback = callback
@@ -1108,7 +1089,6 @@
         self.playlists_sidebar.set_sensitive(not self.header_bar._selectionMode)
         self.menubutton.set_sensitive(not self.header_bar._selectionMode)
 
-
     @log
     def _on_play_activate(self, menuitem, data=None):
         _iter = self._model.get_iter_first()
