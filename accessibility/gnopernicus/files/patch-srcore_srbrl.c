--- srcore/srbrl.c.orig	Sun May 30 03:10:22 2004
+++ srcore/srbrl.c	Sun May 30 03:11:59 2004
@@ -724,6 +724,11 @@
 src_braille_load_values (SRCBraille *braille)
 {
     gint default_int_val;
+    gint default_pos_sensor;
+    gint default_opt_sensor;
+    gchar *default_braille_transaltion_table;
+    gchar *default_braille_style;
+    gchar *default_braille_cursor_style;
     
     sru_assert (braille);
     
@@ -751,7 +756,7 @@
 	}					  
     }    
     
-    gchar *default_braille_transaltion_table = DEFAULT_BRAILLE_TRANSLATION;
+    default_braille_transaltion_table = DEFAULT_BRAILLE_TRANSLATION;
     GET_BRAILLE_CONFIG_DATA_WITH_DEFAULT (BRAILLE_TRANSLATION, CFGT_STRING, 
 					  &braille->translation_table, 
 					  default_braille_transaltion_table);		
@@ -763,22 +768,22 @@
     }
 	
     
-    gchar *default_braille_style = DEFAULT_BRAILLE_STYLE;
+    default_braille_style = DEFAULT_BRAILLE_STYLE;
     GET_BRAILLE_CONFIG_DATA_WITH_DEFAULT (BRAILLE_STYLE, CFGT_STRING, 
 					  &braille->style, 
 					  default_braille_style);
 					  
-    gchar *default_braille_cursor_style = DEFAULT_BRAILLE_CURSOR_STYLE;
+    default_braille_cursor_style = DEFAULT_BRAILLE_CURSOR_STYLE;
     GET_BRAILLE_CONFIG_DATA_WITH_DEFAULT (BRAILLE_CURSOR_STYLE, CFGT_STRING, 
 					  &braille->cursor_style, 
 					  default_braille_cursor_style);
 					  
-    gint default_pos_sensor = DEFAULT_BRAILLE_POSITION_SENSOR;
+    default_pos_sensor = DEFAULT_BRAILLE_POSITION_SENSOR;
     GET_BRAILLE_CONFIG_DATA_WITH_DEFAULT (BRAILLE_POSITION_SENSOR, CFGT_INT, 
 					  &braille->position_sensor, 
 					  &default_pos_sensor);
     
-    gint default_opt_sensor = DEFAULT_BRAILLE_OPTICAL_SENSOR;
+    default_opt_sensor = DEFAULT_BRAILLE_OPTICAL_SENSOR;
     GET_BRAILLE_CONFIG_DATA_WITH_DEFAULT (BRAILLE_OPTICAL_SENSOR, CFGT_INT, 
 					  &braille->optical_sensor, 
 					  &default_opt_sensor);
