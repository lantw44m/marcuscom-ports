
$FreeBSD: ports/graphics/solang/files/patch-src_renderer_browser-model-column-record.h,v 1.1 2009/12/03 12:50:05 pav Exp $

--- src/renderer/browser-model-column-record.h.orig
+++ src/renderer/browser-model-column-record.h
@@ -36,6 +36,8 @@
         virtual
         ~BrowserModelColumnRecord() throw();
 
+        BrowserModelColumnRecord(const BrowserModelColumnRecord&) throw();
+
         const Gtk::TreeModelColumn<guint> &
         get_column_serial() const throw();
 
