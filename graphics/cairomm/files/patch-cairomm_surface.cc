--- cairomm/surface.cc	2006/03/06 17:55:51	1.12
+++ cairomm/surface.cc	2006/06/27 01:46:14	1.15
@@ -76,6 +76,17 @@
   check_object_status_and_throw_exception(*this);
 }
 
+void Surface::get_device_offset(double& x_offset, double& y_offset)
+{
+  cairo_surface_get_device_offset(m_cobject, &x_offset, &y_offset);
+}
+
+void Surface::set_fallback_resolution(double x_pixels_per_inch, double y_pixels_per_inch)
+{
+  cairo_surface_set_fallback_resolution(m_cobject, x_pixels_per_inch, y_pixels_per_inch);
+  check_object_status_and_throw_exception(*this);
+}
+
 #ifdef CAIRO_HAS_PNG_FUNCTIONS
 void Surface::write_to_png(const std::string& filename)
 {
@@ -164,6 +175,25 @@
   return result;
 }
 
+unsigned char* ImageSurface::get_data()
+{
+  return cairo_image_surface_get_data(m_cobject);
+}
+
+const unsigned char* ImageSurface::get_data() const
+{
+  return cairo_image_surface_get_data(m_cobject);
+}
+
+Format ImageSurface::get_format() const
+{
+  return static_cast<Format>(cairo_image_surface_get_format(m_cobject));
+}
+
+int ImageSurface::get_stride() const
+{
+  return cairo_image_surface_get_stride(m_cobject);
+}
 
 
 /*******************************************************************************
@@ -195,9 +225,9 @@
   return RefPtr<PdfSurface>(new PdfSurface(cobject, true /* has reference */));
 }
 
-void PdfSurface::set_dpi(double x_dpi, double y_dpi)
+void PdfSurface::set_size(double width_in_points, double height_in_points)
 {
-  cairo_pdf_surface_set_dpi(m_cobject, x_dpi, y_dpi);
+  cairo_pdf_surface_set_size(m_cobject, width_in_points, height_in_points);
   check_object_status_and_throw_exception(*this);
 }
 
@@ -231,12 +261,32 @@
   return RefPtr<PsSurface>(new PsSurface(cobject, true /* has reference */));
 }
 
-void PsSurface::set_dpi(double x_dpi, double y_dpi)
+void PsSurface::set_size(double width_in_points, double height_in_points)
 {
-  cairo_ps_surface_set_dpi(m_cobject, x_dpi, y_dpi);
+  cairo_ps_surface_set_size(m_cobject, width_in_points, height_in_points);
   check_object_status_and_throw_exception(*this);
 }
 
+
+void PsSurface::dsc_comment(std::string comment)
+{
+  cairo_ps_surface_dsc_comment(m_cobject, comment.c_str());
+  check_object_status_and_throw_exception(*this);
+}
+
+void PsSurface::dsc_begin_setup()
+{
+  cairo_ps_surface_dsc_begin_setup(m_cobject);
+  check_object_status_and_throw_exception(*this);
+}
+
+void PsSurface::dsc_begin_page_setup()
+{
+  cairo_ps_surface_dsc_begin_page_setup(m_cobject);
+  check_object_status_and_throw_exception(*this);
+}
+
+
 #endif // CAIRO_HAS_PS_SURFACE
 
 
@@ -267,12 +317,6 @@
   return RefPtr<SvgSurface>(new SvgSurface(cobject, true /* has reference */));
 }
 
-void SvgSurface::set_dpi(double x_dpi, double y_dpi)
-{
-  cairo_svg_surface_set_dpi(m_cobject, x_dpi, y_dpi);
-  check_object_status_and_throw_exception(*this);
-}
-
 #endif // CAIRO_HAS_SVG_SURFACE
 
 
