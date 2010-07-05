
$FreeBSD: ports/graphics/solang/files/patch-src_attribute_search-basket-column-record.h,v 1.1 2009/12/03 12:50:05 pav Exp $

--- src/attribute/search-basket-column-record.h.orig
+++ src/attribute/search-basket-column-record.h
@@ -34,6 +34,8 @@
     public:
         SearchBasketColumnRecord() throw();
 
+        SearchBasketColumnRecord(const SearchBasketColumnRecord& rec) throw();
+
         virtual
         ~SearchBasketColumnRecord() throw();
 
