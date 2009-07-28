--- WebCore/platform/network/soup/ResourceHandleSoup.cpp.orig	2009-07-25 01:24:42.000000000 +0200
+++ WebCore/platform/network/soup/ResourceHandleSoup.cpp	2009-07-25 01:25:04.000000000 +0200
@@ -530,7 +530,7 @@ bool ResourceHandle::startHttp(String ur
 
                     SoupBuffer* soupBuffer = soup_buffer_new_with_owner(g_mapped_file_get_contents(fileMapping),
                                                                         g_mapped_file_get_length(fileMapping),
-                                                                        fileMapping, reinterpret_cast<GDestroyNotify>(g_mapped_file_free));
+                                                                        fileMapping, reinterpret_cast<GDestroyNotify>(g_mapped_file_unref));
                     soup_message_body_append_buffer(d->m_msg->request_body, soupBuffer);
                     soup_buffer_free(soupBuffer);
                 }
