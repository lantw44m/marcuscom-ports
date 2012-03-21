--- js/gdm/loginDialog.js	2012-03-20 22:08:13.000000000 -0500
+++ js/gdm/loginDialog.js.orig	2012-03-20 22:07:01.000000000 -0500
@@ -301,17 +301,11 @@
         this.actor.connect('key-focus-in', Lang.bind(this, this._moveFocusToItems));
     },
 
-    _hasItems: function() {
-        for (let userName in this._items) {
-            return true;
-        }
-        return false;
-    },
-
     _moveFocusToItems: function() {
-        if (!this._hasItems()) {
+        let hasItems = Object.keys(this._items).length > 0;
+
+        if (!hasItems)
             return;
-        }
 
         if (global.stage.get_key_focus() != this.actor)
             return;
