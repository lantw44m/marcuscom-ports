--- gtk/gtkmm/toolbar.cc.orig	2008-07-09 15:36:27.000000000 -0400
+++ gtk/gtkmm/toolbar.cc	2008-07-09 15:37:10.000000000 -0400
@@ -26,13 +26,6 @@
  * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
-//Define this to make sure that we don't use any of the deprecated GtkToolbar API.
-//Normally we just deprecate it in gtkmm too,
-//but the GtkToolbar compatibility system is particularly unpleasant, so we just removed it in gtkmm 2.4. murrayc.
-//In future, this GTK_DISABLE_DEPRECATED might be inappropriate because it might cover extra GTK+ API. Just remove it then.
-
-#define GTK_DISABLE_DEPRECATED
-
 #include <glib.h>
 #include <gtkmm/button.h>
 #include <gtkmm/togglebutton.h>
@@ -102,7 +95,7 @@ void Toolbar::unset_drop_highlight_item(
 Tooltips* Toolbar::get_tooltips_object() const
 {
   //Note that the _tooltips field is deprecated and broken since GTK+ 2.12:
-  return Glib::wrap((GtkTooltips*)gobj()->_tooltips);
+  return 0; //Glib::wrap((GtkTooltips*)gobj()->_tooltips);
 }
 #endif //GTKMM_DISABLE_DEPRECATED
 
