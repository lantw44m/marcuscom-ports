2004-03-13 Joe Marcus Clarke <marcus@FreeBSD.org>

* embed/mozilla/mozilla-download.cpp: (mozilla_download_class_init):

Register MozillaDownloadPrivate with g_type_class_add_private before calling
G_TYPE_INSTANCE_GET_PRIVATE (fixes #137109).

--- embed/mozilla/mozilla-download.cpp.orig	Sat Mar 13 17:12:45 2004
+++ embed/mozilla/mozilla-download.cpp	Sat Mar 13 17:13:36 2004
@@ -264,6 +264,8 @@
 	download_class->pause = impl_pause;
 	download_class->resume = impl_resume;
 
+	g_type_class_add_private (klass, sizeof (MozillaDownloadPrivate));
+
 	g_object_class_install_property (object_class,
 					 PROP_MOZDOWNLOAD,
 					 g_param_spec_pointer ("mozilla-download",
