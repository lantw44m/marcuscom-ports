diff --git src/libexchangemapi/e-mapi-fast-transfer.c src/libexchangemapi/e-mapi-fast-transfer.c
index 298839b..05fb207 100644
--- src/libexchangemapi/e-mapi-fast-transfer.c
+++ src/libexchangemapi/e-mapi-fast-transfer.c
@@ -30,6 +30,17 @@
 
 #include "e-mapi-fast-transfer.h"
 
+#ifdef HAVE_FAST_TRANSFER_TAGS_2_1
+#define StartMessage PidTagStartMessage
+#define EndMessage PidTagEndMessage
+#define StartRecip PidTagStartRecip
+#define EndToRecip PidTagEndToRecip
+#define NewAttach PidTagNewAttach
+#define EndAttach PidTagEndAttach
+#define StartEmbed PidTagStartEmbed
+#define EndEmbed PidTagEndEmbed
+#endif
+
 struct _EMapiFXParserClosure;
 typedef struct _EMapiFXParserClosure EMapiFXParserClosure;
 
@@ -107,9 +118,9 @@ parse_marker_cb (uint32_t marker, void *closure)
 
 	/* g_print ("\tMarker: %s (0x%08x)\n", get_proptag_name (marker), marker); */
 	switch (marker) {
-		case PidTagStartMessage:
+		case StartMessage:
 			if (data->object) {
-				g_debug ("%s: PidTagStartMessage: out of order, previous object not finished yet", G_STRFUNC);
+				g_debug ("%s: StartMessage: out of order, previous object not finished yet", G_STRFUNC);
 				e_mapi_object_finish_read (data->object);
 				stop = !process_parsed_object (data);
 				e_mapi_object_free (data->object);
@@ -134,9 +145,9 @@ parse_marker_cb (uint32_t marker, void *closure)
 			data->current_streamed_properties_count = &data->object->streamed_properties_count;
 			data->marker = marker;
 			break;
-		case PidTagEndMessage:
+		case EndMessage:
 			if (!data->object) {
-				g_debug ("%s: PidTagEndMessage no object started", G_STRFUNC);
+				g_debug ("%s: EndMessage no object started", G_STRFUNC);
 			} else {
 				e_mapi_object_finish_read (data->object);
 				stop = !process_parsed_object (data);
@@ -154,9 +165,9 @@ parse_marker_cb (uint32_t marker, void *closure)
 			}
 			data->marker = 0;
 			break;
-		case PidTagStartRecip:
+		case StartRecip:
 			if (!data->current_object) {
-				g_debug ("%s: PidTagStartRecip no object started", G_STRFUNC);
+				g_debug ("%s: StartRecip no object started", G_STRFUNC);
 			} else {
 				EMapiRecipient *recipient;
 
@@ -173,16 +184,16 @@ parse_marker_cb (uint32_t marker, void *closure)
 			}
 			data->marker = marker;
 			break;
-		case PidTagEndToRecip:
+		case EndToRecip:
 			data->current_properties = NULL;
 			data->current_streamed_mem_ctx = NULL;
 			data->current_streamed_properties = NULL;
 			data->current_streamed_properties_count = NULL;
 			data->marker = 0;
 			break;
-		case PidTagNewAttach:
+		case NewAttach:
 			if (!data->current_object) {
-				g_debug ("%s: PidTagNewAttach no object started", G_STRFUNC);
+				g_debug ("%s: NewAttach no object started", G_STRFUNC);
 			} else {
 				EMapiAttachment *attachment;
 
@@ -199,20 +210,20 @@ parse_marker_cb (uint32_t marker, void *closure)
 			}
 			data->marker = marker;
 			break;
-		case PidTagEndAttach:
+		case EndAttach:
 			data->current_properties = NULL;
 			data->current_streamed_mem_ctx = NULL;
 			data->current_streamed_properties = NULL;
 			data->current_streamed_properties_count = NULL;
 			data->marker = 0;
 			break;
-		case PidTagStartEmbed:
+		case StartEmbed:
 			if (!data->current_object) {
-				g_debug ("%s: PidTagStartEmbed no object started", G_STRFUNC);
+				g_debug ("%s: StartEmbed no object started", G_STRFUNC);
 			} else if (!data->current_object->attachments) {
-				g_debug ("%s: PidTagStartEmbed no attachment started", G_STRFUNC);
+				g_debug ("%s: StartEmbed no attachment started", G_STRFUNC);
 			} else if (data->current_object->attachments->embedded_object) {
-				g_debug ("%s: PidTagStartEmbed attachment has embedded object already", G_STRFUNC);
+				g_debug ("%s: StartEmbed attachment has embedded object already", G_STRFUNC);
 			} else {
 				EMapiObject *object;
 
@@ -228,11 +239,11 @@ parse_marker_cb (uint32_t marker, void *closure)
 			}
 			data->marker = marker;
 			break;
-		case PidTagEndEmbed:
+		case EndEmbed:
 			if (!data->current_object) {
-				g_debug ("%s: PidTagEndEmbed no object started", G_STRFUNC);
+				g_debug ("%s: EndEmbed no object started", G_STRFUNC);
 			} else if (!data->current_object->parent) {
-				g_debug ("%s: PidTagEndEmbed no parent object", G_STRFUNC);
+				g_debug ("%s: EndEmbed no parent object", G_STRFUNC);
 			} else {
 				e_mapi_object_finish_read (data->current_object);
 				data->current_object = data->current_object->parent;
@@ -397,7 +408,7 @@ e_mapi_fast_transfer_internal (EMapiConnection *conn,
 		data.current_streamed_mem_ctx = data.object;
 		data.current_streamed_properties = &data.object->streamed_properties;
 		data.current_streamed_properties_count = &data.object->streamed_properties_count;
-		data.marker = PidTagStartMessage;
+		data.marker = StartMessage;
 	}
 		
 	parser = fxparser_init (data.mem_ctx, &data);
