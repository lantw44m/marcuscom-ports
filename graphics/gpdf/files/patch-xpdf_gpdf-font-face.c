--- xpdf/gpdf-font-face.c.orig	Thu Feb  5 16:36:51 2004
+++ xpdf/gpdf-font-face.c	Thu Feb  5 16:43:38 2004
@@ -151,7 +151,6 @@
 	entry->speciesname = g_strdup (species
 				       ? species
 				       : (const guchar*) "Regular");
-	entry->weight = entry->speciesname; /* FIXME here and in fcpattern_to_gp_font_entry */
 	entry->Weight = weight;
 	entry->familyname = g_strdup (family);
 	entry->name = g_strconcat (family, " ", entry->speciesname, NULL);
