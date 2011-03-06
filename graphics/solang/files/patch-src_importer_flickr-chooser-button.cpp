
$FreeBSD: ports/graphics/solang/files/patch-src_importer_flickr-chooser-button.cpp,v 1.1 2009/12/03 12:50:05 pav Exp $

--- src/importer/flickr-chooser-button.cpp.orig
+++ src/importer/flickr-chooser-button.cpp
@@ -53,6 +53,8 @@
         virtual
         ~FlickrButtonModelColumnRecord() throw();
 
+        FlickrButtonModelColumnRecord(const FlickrButtonModelColumnRecord&) throw();
+
         const Gtk::TreeModelColumn<PixbufPtr> &
         get_column_pixbuf() const throw();
 
