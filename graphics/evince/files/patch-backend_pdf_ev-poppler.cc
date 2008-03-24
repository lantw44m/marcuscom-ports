--- backend/pdf/ev-poppler.cc	2008/03/10 20:06:22	2964
+++ backend/pdf/ev-poppler.cc	2008/03/14 11:13:01	2965
@@ -53,6 +53,14 @@
 #define HAVE_CAIRO_PRINT
 #endif
 
+#if 7 <= 6 || (7 == 7 && 3 < 2)
+#define POPPLER_HAS_GDK
+#else
+#ifdef POPPLER_WITH_GDK
+#define POPPLER_HAS_GDK
+#endif
+#endif
+
 typedef struct {
 	PdfDocument *document;
 	char *text;
@@ -445,27 +453,12 @@
 }
 
 static cairo_surface_t *
-pdf_document_render (EvDocument      *document,
-		     EvRenderContext *rc)
+pdf_page_render (PopplerPage     *page,
+		 gint             width,
+		 gint             height,
+		 EvRenderContext *rc)
 {
-	PdfDocument *pdf_document;
 	cairo_surface_t *surface;
-	double width_points, height_points;
-	gint width, height;
-
-	pdf_document = PDF_DOCUMENT (document);
-
-	set_rc_data (pdf_document, rc);
-
-	poppler_page_get_size (POPPLER_PAGE (rc->data), &width_points, &height_points);
-
-	if (rc->rotation == 90 || rc->rotation == 270) {
-		width = (int) ((height_points * rc->scale) + 0.5);
-		height = (int) ((width_points * rc->scale) + 0.5);
-	} else {
-		width = (int) ((width_points * rc->scale) + 0.5);
-		height = (int) ((height_points * rc->scale) + 0.5);
-	}
 
 #ifdef HAVE_POPPLER_PAGE_RENDER
 	cairo_t *cr;
@@ -492,7 +485,7 @@
 	}
 	cairo_scale (cr, rc->scale, rc->scale);
 	cairo_rotate (cr, rc->rotation * G_PI / 180.0);
-	poppler_page_render (POPPLER_PAGE (rc->data), cr);
+	poppler_page_render (page, cr);
 	cairo_destroy (cr);
 #else /* HAVE_POPPLER_PAGE_RENDER */
 	GdkPixbuf *pixbuf;
@@ -501,7 +494,7 @@
 				 FALSE, 8,
 				 width, height);
 
-	poppler_page_render_to_pixbuf (POPPLER_PAGE (rc->data),
+	poppler_page_render_to_pixbuf (page,
 				       0, 0,
 				       width, height,
 				       rc->scale,
@@ -511,7 +504,34 @@
 	g_object_unref (pixbuf);
 #endif /* HAVE_POPPLER_PAGE_RENDER */
 
-	return surface;
+	return surface;	
+}
+
+static cairo_surface_t *
+pdf_document_render (EvDocument      *document,
+		     EvRenderContext *rc)
+{
+	PdfDocument *pdf_document;
+	double width_points, height_points;
+	gint width, height;
+
+	pdf_document = PDF_DOCUMENT (document);
+
+	set_rc_data (pdf_document, rc);
+
+	poppler_page_get_size (POPPLER_PAGE (rc->data),
+			       &width_points, &height_points);
+	
+	if (rc->rotation == 90 || rc->rotation == 270) {
+		width = (int) ((height_points * rc->scale) + 0.5);
+		height = (int) ((width_points * rc->scale) + 0.5);
+	} else {
+		width = (int) ((width_points * rc->scale) + 0.5);
+		height = (int) ((height_points * rc->scale) + 0.5);
+	}
+	
+	return pdf_page_render (POPPLER_PAGE (rc->data),
+				width, height, rc);
 }
 
 /* EvDocumentSecurity */
@@ -1178,7 +1198,7 @@
 		ev_image_mapping = g_new (EvImageMapping, 1);
 #ifdef HAVE_POPPLER_PAGE_GET_IMAGE
 		ev_image_mapping->image = ev_image_new (page, image_mapping->image_id);
-#else
+#elif POPPLER_HAS_CAIRO
 		ev_image_mapping->image = ev_image_new_from_pixbuf (image_mapping->image);
 #endif
 		ev_image_mapping->x1 = image_mapping->area.x1;
@@ -1240,7 +1260,7 @@
 
 	pdf_document_thumbnails_get_dimensions (EV_DOCUMENT_THUMBNAILS (pdf_document),
 						rc, &width, &height);
-
+#ifdef POPPLER_HAS_GDK
 	pixbuf = gdk_pixbuf_new (GDK_COLORSPACE_RGB, FALSE, 8,
 				 width, height);
 	gdk_pixbuf_fill (pixbuf, 0xffffffff);
@@ -1250,6 +1270,16 @@
 				       width, height,
 				       rc->scale, rc->rotation, pixbuf);
 	ev_document_fc_mutex_unlock ();
+#else
+	cairo_surface_t *surface;
+
+	ev_document_fc_mutex_lock ();
+	surface = pdf_page_render (poppler_page, width, height, rc);
+	ev_document_fc_mutex_unlock ();
+	
+	pixbuf = ev_document_misc_pixbuf_from_surface (surface);
+	cairo_surface_destroy (surface);
+#endif /* POPPLER_HAS_GDK */
 
 	return pixbuf;
 }
@@ -1261,7 +1291,7 @@
 {
 	PdfDocument *pdf_document;
 	PopplerPage *poppler_page;
-	GdkPixbuf *pixbuf;
+	GdkPixbuf *pixbuf = NULL;
 	GdkPixbuf *border_pixbuf;
 
 	pdf_document = PDF_DOCUMENT (document_thumbnails);
@@ -1269,7 +1299,22 @@
 	poppler_page = poppler_document_get_page (pdf_document->document, rc->page);
 	g_return_val_if_fail (poppler_page != NULL, NULL);
 
+#if 7 <= 6 || (7 == 7 && 3 < 2)
 	pixbuf = poppler_page_get_thumbnail (poppler_page);
+#else
+#ifdef POPPLER_HAS_GDK
+	pixbuf = poppler_page_get_thumbnail_pixbuf (poppler_page);
+#else
+	cairo_surface_t *surface;
+	
+	surface = poppler_page_get_thumbnail (poppler_page);
+	if (surface) {
+		pixbuf = ev_document_misc_pixbuf_from_surface (surface);
+		cairo_surface_destroy (surface);
+	}
+#endif
+#endif
+		
 	if (pixbuf) {
 		/* Rotate provided thumbnail if needed */
 		GdkPixbuf *rotated_pixbuf;
@@ -1855,6 +1900,23 @@
 
 #ifdef HAVE_POPPLER_PAGE_RENDER
 	cairo_t *cr;
+	
+#if 7 <= 6 || (7 == 7 && 3 < 2)
+	GdkColor **text_color, **base_color;
+
+	*text_color = text;
+	*base_color = base;
+#else
+	PopplerColor text_color, base_color;
+	
+	text_color.red = text->red;
+	text_color.green = text->green;
+	text_color.blue = text->blue;
+
+	base_color.red = base->red;
+	base_color.green = base->green;
+	base_color.blue = base->blue;
+#endif
 
 	if (*surface == NULL) {
 		*surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32,
@@ -1873,8 +1935,8 @@
 				       (PopplerRectangle *)points,
 				       (PopplerRectangle *)old_points,
 				       (PopplerSelectionStyle)style,
-				       text,
-				       base);
+				       &text_color,
+				       &base_color);
 	cairo_destroy (cr);
 #else /* HAVE_POPPLER_PAGE_RENDER */
 	GdkPixbuf *pixbuf;
@@ -1928,22 +1990,60 @@
 }
 
 static GdkRegion *
+create_gdk_region_from_poppler_region (GList *region)
+{
+	GList *l;
+	GdkRegion *retval;
+	
+	retval = gdk_region_new ();
+	
+	for (l = region; l; l = g_list_next (l)) {
+		PopplerRectangle *rectangle;
+		GdkRectangle      rect;
+		
+		rectangle = (PopplerRectangle *)l->data;
+		
+		rect.x = (gint) rectangle->x1;
+		rect.y = (gint) rectangle->y1;
+		rect.width  = (gint) (rectangle->x2 - rectangle->x1);
+		rect.height = (gint) (rectangle->y2 - rectangle->y1);
+		gdk_region_union_with_rect (retval, &rect);
+		
+		poppler_rectangle_free (rectangle);
+	}
+
+	return retval;
+}
+
+static GdkRegion *
 pdf_selection_get_selection_region (EvSelection     *selection,
 				    EvRenderContext *rc,
 				    EvSelectionStyle style,
 				    EvRectangle     *points)
 {
 	PdfDocument *pdf_document;
-	GdkRegion *retval;
+	GdkRegion   *retval;
 
 	pdf_document = PDF_DOCUMENT (selection);
 
 	set_rc_data (pdf_document, rc);
-
-	retval = poppler_page_get_selection_region ((PopplerPage *)rc->data,
+	
+#if 7 <= 6 || (7 == 7 && 3 < 2)
+	retval = poppler_page_get_selection_region (POPPLER_PAGE (rc->data),
 						    rc->scale,
 						    (PopplerSelectionStyle)style,
 						    (PopplerRectangle *) points);
+#else
+	GList *region;
+	
+	region = poppler_page_get_selection_region (POPPLER_PAGE (rc->data),
+						    rc->scale,
+						    (PopplerSelectionStyle)style,
+						    (PopplerRectangle *) points);
+	retval = create_gdk_region_from_poppler_region (region);
+	g_list_free (region);
+#endif
+	
 	return retval;
 }
 
@@ -1954,6 +2054,7 @@
 	PdfDocument *pdf_document;
 	PopplerPage *poppler_page;
 	PopplerRectangle points;
+	GList *region;
 	GdkRegion *retval;
 
 	pdf_document = PDF_DOCUMENT (selection);
@@ -1963,9 +2064,18 @@
 	points.x1 = 0.0;
 	points.y1 = 0.0;
 	poppler_page_get_size (poppler_page, &(points.x2), &(points.y2));
+	
+#if 7 <= 6 || (7 == 7 && 3 < 2)
 	retval = poppler_page_get_selection_region (poppler_page, 1.0,
 						    POPPLER_SELECTION_GLYPH,
 						    &points);
+#else
+	region = poppler_page_get_selection_region (poppler_page, 1.0,
+						    POPPLER_SELECTION_GLYPH,
+						    &points);
+	retval = create_gdk_region_from_poppler_region (region);
+	g_list_free (region);
+#endif
 	g_object_unref (poppler_page);
 
 	return retval;
