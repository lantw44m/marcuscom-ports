--- glib/glibmm/ustring.cc.orig	2010-06-01 15:36:11.000000000 +0200
+++ glib/glibmm/ustring.cc	2010-06-19 09:44:25.000000000 +0200
@@ -1354,7 +1354,12 @@ std::wistream& operator>>(std::wistream&
   glong n_bytes = 0;
   const ScopedPtr<char> buf (g_utf16_to_utf8(reinterpret_cast<const gunichar2*>(wstr.data()),
                                              wstr.size(), 0, &n_bytes, &error));
-#endif //GLIBMM_EXCEPTIONS_ENABLED
+#else
+  gsize n_bytes = 0;
+  const ScopedPtr<char> buf (g_convert(reinterpret_cast<const char*>(wstr.data()),
+                                       wstr.size() * sizeof(std::wstring::value_type),
+                                       "UTF-8", "WCHAR_T", 0, &n_bytes, &error));
+#endif // !(__STDC_ISO_10646__ || G_OS_WIN32)
 
   if (error)
   {
@@ -1378,7 +1383,13 @@ std::wostream& operator<<(std::wostream&
   // Avoid going through iconv if wchar_t always contains UTF-16.
   const ScopedPtr<gunichar2> buf (g_utf8_to_utf16(utf8_string.raw().data(),
                                                   utf8_string.raw().size(), 0, 0, &error));
-#endif //GLIBMM_EXCEPTIONS_ENABLED
+#else
+  // TODO: For some reason the conversion from UTF-8 to WCHAR_T doesn't work
+  // with g_convert(), while iconv on the command line handles it just fine.
+  // Maybe a bug in GLib?
+  const ScopedPtr<char> buf (g_convert(utf8_string.raw().data(), utf8_string.raw().size(),
+                                       "WCHAR_T", "UTF-8", 0, 0, &error));
+#endif // !(__STDC_ISO_10646__ || G_OS_WIN32)
 
   if (error)
   {
