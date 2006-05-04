--- gui/greeter/greeter_parser.c.orig	Thu May  4 14:11:25 2006
+++ gui/greeter/greeter_parser.c	Thu May  4 14:11:33 2006
@@ -506,6 +506,8 @@ parse_gtkbutton (xmlNodePtr node,
 		
   child = node->children;
 
+  translated_text = NULL;
+
   while (child)
     {
       if (strcmp ((char *) child->name, "pos") == 0)
