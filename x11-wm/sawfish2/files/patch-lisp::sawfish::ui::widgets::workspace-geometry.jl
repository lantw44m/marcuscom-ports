
$FreeBSD: ports/x11-wm/sawfish2/files/patch-lisp::sawfish::ui::widgets::workspace-geometry.jl,v 1.1 2002/05/14 22:26:39 sobomax Exp $

--- lisp/sawfish/ui/widgets/workspace-geometry.jl	2002/04/29 19:16:50	1.1
+++ lisp/sawfish/ui/widgets/workspace-geometry.jl	2002/04/29 19:17:07
@@ -28,7 +28,6 @@
     (open rep
 	  gui.gtk-2.gtk
 	  gui.gtk-2.gnome-canvas
-	  gui.gtk-2.gdk-pixbuf
 	  rep.io.files
 	  sawfish.gtk.widget
 	  sawfish.ui.layout)
