--- gtk/gtkmm/toolbar.cc.orig	Thu Dec 11 16:01:25 2003
+++ gtk/gtkmm/toolbar.cc	Thu Dec 11 16:02:55 2003
@@ -412,8 +412,10 @@
 Toolbar::ToolList& Toolbar::tools()
 {
   //Create the instance if it hasn't been created yet:
-  if(!tools_proxy_.get())
-    tools_proxy_ = tools_proxy_ptr_type(new ToolList);
+  if(!tools_proxy_.get()) {
+    tools_proxy_ptr_type _tp(new ToolList);
+    tools_proxy_ = _tp;
+  }
 
   //Update it (this might not be necessary):
   *tools_proxy_ = ToolList(gobj());
@@ -424,8 +426,10 @@
 const Toolbar::ToolList& Toolbar::tools() const
 {
   //Create the instance if it hasn't been created yet:
-  if(!tools_proxy_.get())
-    tools_proxy_ = tools_proxy_ptr_type(new ToolList);
+  if(!tools_proxy_.get()) {
+    tools_proxy_ptr_type _tp(new ToolList);
+    tools_proxy_ = _tp;
+  }
 
   //Update it (this might not be necessary):
   *tools_proxy_ = ToolList(const_cast<GtkToolbar*>(gobj()));
