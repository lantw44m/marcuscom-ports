--- drivers/festival/festivalsynthesisdriver.c.orig	Tue Aug 12 14:59:50 2003
+++ drivers/festival/festivalsynthesisdriver.c	Tue Aug 12 15:00:08 2003
@@ -338,8 +338,8 @@
 static void
 festival_synthesis_driver_class_init (FestivalSynthesisDriverClass *klass)
 {
-	parent_class = g_type_class_peek_parent (klass);
 	GObjectClass *object_class = G_OBJECT_CLASS(klass);
+	parent_class = g_type_class_peek_parent (klass);
 
 	object_class->finalize = festival_synthesis_driver_finalize;
 	
