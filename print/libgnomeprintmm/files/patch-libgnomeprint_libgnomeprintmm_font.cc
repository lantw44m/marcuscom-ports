--- libgnomeprint/libgnomeprintmm/font.cc.orig	Wed Dec 17 19:59:13 2003
+++ libgnomeprint/libgnomeprintmm/font.cc	Wed Dec 17 19:59:29 2003
@@ -180,7 +180,7 @@
 
 Glib::RefPtr<Font> Font::find_closest(const Glib::ustring& family, FontWeight weight, bool italic, double size)
 {
-  return Glib::wrap(gnome_font_find_closest_from_weight_slant((const guchar*)family.c_str(), static_cast<GnomeFontWeight>(weight), static_cast<int>(italic), size));
+  return Glib::wrap(gnome_font_find_closest_from_weight_slant((const guchar*)family.c_str(), (GnomeFontWeight)(weight), static_cast<int>(italic), size));
 }
 
 Glib::RefPtr<Pango::Font> Font::get_closest_pango_font(const Glib::RefPtr<Pango::FontMap>& map, double dpi) const
