--- cairomm/surface.h	2006/03/06 17:55:51	1.10
+++ cairomm/surface.h	2006/06/27 01:46:14	1.13
@@ -137,6 +137,17 @@
    */
   void set_device_offset(double x_offset, double y_offset);
 
+  /** Returns a previous device offset set by set_device_offset().
+   */
+  void get_device_offset(double& x_offset, double& y_offset);
+
+  /** Sets the fallback resolution of the image in dots per inch
+   *
+   * @param x_pixels_per_inch   Pixels per inch in the x direction
+   * @param y_pixels_per_inch   Pixels per inch in the y direction
+   */
+  void set_fallback_resolution(double x_pixels_per_inch, double y_pixels_per_inch);
+
 #ifdef CAIRO_HAS_PNG_FUNCTIONS
 
   /** Writes the contents of surface to a new file filename as a PNG image.
@@ -243,6 +254,29 @@
    */
   int get_height() const;
 
+  /**
+   * Get a pointer to the data of the image surface, for direct
+   * inspection or modification.
+   *
+   * Return value: a pointer to the image data of this surface or NULL
+   * if @surface is not an image surface.
+   */
+  unsigned char* get_data();
+  const unsigned char* get_data() const;
+
+  /** gets the format of the surface
+   */
+  Format get_format() const;
+
+  /**
+   * Return value: the stride of the image surface in bytes (or 0 if
+   * @surface is not an image surface). The stride is the distance in
+   * bytes from the beginning of one row of the image data to the
+   * beginning of the next row.
+   */
+  int get_stride() const;
+
+
   /** Creates an image surface of the specified format and dimensions. The
    * initial contents of the surface is undefined; you must explicitely clear
    * the buffer, using, for example, Cairo::Context::rectangle() and
@@ -367,12 +401,19 @@
    */
   static RefPtr<PdfSurface> create(cairo_write_func_t write_func, void *closure, double width_in_points, double height_in_points);
 
-  /** Sets the resolution of the image in dots per inch
-   *
-   * @param x_dpi   The dpi in the x direction
-   * @param y_dpi    The dpi in the y direction
-   */
-  void set_dpi(double x_dpi, double y_dpi);
+/**
+ * Changes the size of a PDF surface for the current (and subsequent) pages.
+ *
+ * This function should only be called before any drawing operations have been
+ * performed on the current page. The simplest way to do this is to call this
+ * function immediately after creating the surface or immediately after
+ * completing a page with either Context::show_page() or Context::copy_page().
+ *
+ * \param width_in_points new surface width, in points (1 point == 1/72.0 inch)
+ * \param height_in_points new surface height, in points (1 point == 1/72.0 inch)
+ **/
+  void set_size(double width_in_points, double height_in_points);
+
 };
 
 #endif  // CAIRO_HAS_PDF_SURFACE
@@ -424,12 +465,45 @@
    */
   static RefPtr<PsSurface> create(cairo_write_func_t write_func, void *closure, double width_in_points, double height_in_points);
 
-  /** Sets the resolution of the image in dots per inch
+  /**
+   * Changes the size of a PostScript surface for the current (and
+   * subsequent) pages.
+   *
+   * This function should only be called before any drawing operations have been
+   * performed on the current page. The simplest way to do this is to call this
+   * function immediately after creating the surface or immediately after
+   * completing a page with either Context::show_page() or Context::copy_page().
+   *
+   * \param width_in_points new surface width, in points (1 point == 1/72.0 inch)
+   * \param height_in_points new surface height, in points (1 point == 1/72.0 inch)
+   */
+  void set_size(double width_in_points, double height_in_points);
+
+  /** Emit a comment into the PostScript output for the given surface.  See the
+   * cairo reference documentation for more information.
+   *
+   * \param comment a comment string to be emitted into the PostScript output
+   */
+  void dsc_comment(std::string comment);
+
+  /**
+   * This function indicates that subsequent calls to dsc_comment() should direct
+   * comments to the Setup section of the PostScript output.
    *
-   * @param x_dpi   The dpi in the x direction
-   * @param y_dpi    The dpi in the y direction
+   * This function should be called at most once per surface, and must be called
+   * before any call to dsc_begin_page_setup() and before any drawing is performed
+   * to the surface.
    */
-  void set_dpi(double x_dpi, double y_dpi);
+  void dsc_begin_setup();
+
+  /** This function indicates that subsequent calls to dsc_comment() should
+   * direct comments to the PageSetup section of the PostScript output.
+   *
+   * This function call is only needed for the first page of a surface. It
+   * should be called after any call to dsc_begin_setup() and before any drawing
+   * is performed to the surface.
+   */
+  void dsc_begin_page_setup();
 
 };
 
@@ -483,12 +557,6 @@
    */
   static RefPtr<SvgSurface> create(cairo_write_func_t write_func, void *closure, double width_in_points, double height_in_points);
 
-  /** Sets the resolution of the image in dots per inch
-   *
-   * @param x_dpi   The dpi in the x direction
-   * @param y_dpi    The dpi in the y direction
-   */
-  void set_dpi(double x_dpi, double y_dpi);
 };
 
 #endif // CAIRO_HAS_SVG_SURFACE
