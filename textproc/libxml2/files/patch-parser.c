diff --git a/parser.c b/parser.c
index 4e5dcb9..c55e41d 100644
--- parser.c.orig
+++ parser.c
@@ -2709,7 +2709,7 @@ xmlStringLenDecodeEntities(xmlParserCtxtPtr ctxt, const xmlChar *str, int len,
 
 		buffer[nbchars++] = '&';
 		if (nbchars > buffer_size - i - XML_PARSER_BUFFER_SIZE) {
-		    growBuffer(buffer, XML_PARSER_BUFFER_SIZE);
+		    growBuffer(buffer, i + XML_PARSER_BUFFER_SIZE);
 		}
 		for (;i > 0;i--)
 		    buffer[nbchars++] = *cur++;
