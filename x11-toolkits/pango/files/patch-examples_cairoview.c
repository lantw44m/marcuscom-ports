===================================================================
RCS file: /cvs/gnome/pango/examples/cairoview.c,v
retrieving revision 1.11
retrieving revision 1.12
diff -u -r1.11 -r1.12
--- examples/cairoview.c	2005/07/26 11:08:08	1.11
+++ examples/cairoview.c	2005/08/09 21:56:06	1.12
@@ -33,9 +33,8 @@
 
 #include <pango/pangocairo.h>
 #include <cairo-xlib.h>
-#include <pixman.h>
 
-static pixman_region16_t *update_region = NULL;
+static Region update_region = NULL;
 static PangoContext *context;
 static Display *display;
 int screen;
@@ -131,18 +130,14 @@
   cairo_t *cr;
   Pixmap pixmap;
   GC gc;
-  pixman_box16_t *extents;
+  XRectangle extents;
   int width, height;
-  int n_rects;
-  pixman_box16_t *rects;
-  XRectangle *xrects;
-  int i;
 
   /* Create a temporary pixmap and a Cairo context pointing to it */
-  extents = pixman_region_extents (update_region);
+  XClipBox (update_region, &extents);
 
-  width = extents->x2 - extents->x1;
-  height = extents->y2 - extents->y1;
+  width = extents.width;
+  height = extents.height;
 
   pixmap = XCreatePixmap (display, window, width, height,
 			  DefaultDepth (display, screen));
@@ -155,26 +150,13 @@
   cr = render_data.cr = cairo_create (surface);
   cairo_surface_destroy (surface);
   
-  render_data.x_offset = - extents->x1;
-  render_data.y_offset = - extents->y1;
+  render_data.x_offset = - extents.x;
+  render_data.y_offset = - extents.y;
 
   do_cairo_transform (context, NULL, &render_data);
 
   /* Clip to the current update region and fill with white */
-  n_rects = pixman_region_num_rects (update_region);
-  rects = pixman_region_rects (update_region);
-  xrects = g_new (XRectangle, n_rects);
-
-  for (i = 0; i < n_rects; i++)
-    {
-      xrects[i].x = rects[i].x1;
-      xrects[i].y = rects[i].y1;
-      xrects[i].width = rects[i].x2 - rects[i].x1;
-      xrects[i].height = rects[i].y2 - rects[i].y1;
-      
-      cairo_rectangle (cr, xrects[i].x, xrects[i].y,
-		       xrects[i].width, xrects[i].height);
-    }
+  cairo_rectangle (cr, extents.x, extents.y, extents.width, extents.height);
   
   cairo_clip (cr);
   cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
@@ -187,29 +169,30 @@
 
   /* Copy the updated area onto the window */
   gc = XCreateGC (display, pixmap, 0, NULL);
-  XSetClipRectangles (display, gc, 0, 0, xrects, n_rects, YXBanded);
 
   XCopyArea (display, pixmap, window, gc,
 	     0, 0,
-	     extents->x2 - extents->x1, extents->y2 - extents->y1,
-	     extents->x1, extents->y1);
+	     extents.width, extents.height, extents.x, extents.y);
 
-  g_free (xrects);
   XFreeGC (display, gc);
   XFreePixmap (display, pixmap);
 	     
-  pixman_region_destroy (update_region);
+  XDestroyRegion (update_region);
   update_region = NULL;
 }
 
 void
 expose (XExposeEvent *xev)
 {
+  XRectangle  r;
   if (!update_region)
-    update_region = pixman_region_create ();
+    update_region = XCreateRegion ();
 
-  pixman_region_union_rect (update_region, update_region,
-			    xev->x, xev->y, xev->width, xev->height);
+  r.x = xev->x;
+  r.y = xev->y;
+  r.width = xev->width;
+  r.height = xev->height;
+  XUnionRectWithRegion (&r, update_region, update_region);
 }
 
 int main (int argc, char **argv)
@@ -281,12 +264,17 @@
 	  goto done;
 	else if (xev.xkey.keycode == borders_keycode)
 	  {
+	    XRectangle  r;
 	    show_borders = !show_borders;
+
 	    if (!update_region)
-	      update_region = pixman_region_create ();
+	      update_region = XCreateRegion ();
 
-	    pixman_region_union_rect (update_region, update_region,
-				      0, 0, width, height);
+	    r.x = 0;
+	    r.y = 0;
+	    r.width = width;
+	    r.height = height;
+	    XUnionRectWithRegion (&r, update_region, update_region);
 	  }
 	break;
       case Expose:
