--- rsvg-styles.c.orig	Tue Jun  1 18:10:27 2004
+++ rsvg-styles.c	Tue Jun  1 18:11:11 2004
@@ -839,16 +839,16 @@
 	if (status != CR_OK)
         {
 			g_warning (_("Error setting CSS SAC handler"));
-			cr_parser_destroy (parser);
 			cr_doc_handler_destroy (css_handler);
+			cr_parser_destroy (parser);
 			return;
         }        
 	
 	status = cr_parser_set_use_core_grammar (parser, FALSE);
 	status = cr_parser_parse (parser);
 	
-	cr_parser_destroy (parser);
 	cr_doc_handler_destroy (css_handler);
+	cr_parser_destroy (parser);
 }
 
 #else /* !HAVE_LIBCROCO */
