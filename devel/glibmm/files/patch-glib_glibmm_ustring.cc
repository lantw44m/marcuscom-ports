--- glib/glibmm/ustring.cc.orig	2010-06-18 21:49:11.000000000 +0200
+++ glib/glibmm/ustring.cc	2010-06-18 22:03:33.000000000 +0200
@@ -1361,7 +1361,7 @@
     Glib::Error::throw_exception(error);
   }
 
-  utf8_string.assign(buf.get(), buf.get() + n_bytes);
+//  utf8_string.assign(buf.get(), buf.get() + n_bytes);
 
   return is;
 }
@@ -1392,7 +1392,7 @@
   // NUL.  Given this, there doesn't seem much of a point in allowing NUL in
   // formatted output.  The semantics would be unclear anyway: what's the
   // screen width of a NUL?
-  os << reinterpret_cast<wchar_t*>(buf.get());
+//  os << reinterpret_cast<wchar_t*>(buf.get());
 
   return os;
 }
