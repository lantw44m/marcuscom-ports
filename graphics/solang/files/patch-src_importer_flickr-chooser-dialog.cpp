
$FreeBSD: ports/graphics/solang/files/patch-src_importer_flickr-chooser-dialog.cpp,v 1.1 2009/12/03 12:50:05 pav Exp $

--- src/importer/flickr-chooser-dialog.cpp.orig
+++ src/importer/flickr-chooser-dialog.cpp
@@ -80,6 +80,8 @@
         virtual
         ~FlickrDialogModelColumnRecord() throw();
 
+        FlickrDialogModelColumnRecord(const FlickrDialogModelColumnRecord&) throw();
+
         const Gtk::TreeModelColumn<bool> &
         get_column_selected() const throw();
 
