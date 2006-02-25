--- poppler/GlobalParams.cc.orig	Sat Feb 25 04:48:29 2006
+++ poppler/GlobalParams.cc	Sat Feb 25 04:55:02 2006
@@ -1266,7 +1266,7 @@ FcPattern *buildFcPattern(GfxFont *font)
 
 DisplayFontParam *GlobalParams::getDisplayFont(GfxFont *font) {
   DisplayFontParam *dfp;
-  FcPattern *p=0,*m=0;
+  FcPattern *p=0;
 
   GooString *fontName = font->getName();
   if (!fontName) return NULL;
@@ -1278,38 +1278,43 @@ DisplayFontParam *GlobalParams::getDispl
     FcChar8* s;
     char * ext;
     FcResult res;
+    FcFontSet *set;
+    int i;
     p = buildFcPattern(font);
 
     if (!p)
       goto fin;
     FcConfigSubstitute(FCcfg, p, FcMatchPattern);
     FcDefaultSubstitute(p);
-    m = FcFontMatch(FCcfg,p,&res);
-    if (!m)
-      goto fin; 
-    res = FcPatternGetString(m, FC_FILE, 0, &s);
-    if (res != FcResultMatch || !s)
-      goto fin; 
-    ext = strrchr((char*)s,'.');
-    if (!ext)
+    set = FcFontSort(FCcfg, p, FcFalse, NULL, &res);
+    if (!set)
       goto fin;
-    if (!strncasecmp(ext,".ttf",4))
+    for (i = 0; i < set->nfont; ++i)
     {
-      dfp = new DisplayFontParam(fontName->copy(), displayFontTT);  
-      dfp->tt.fileName = new GooString((char*)s);
+	res = FcPatternGetString(set->fonts[i], FC_FILE, 0, &s);
+	if (res != FcResultMatch || !s)
+	    continue;
+	ext = strrchr((char*)s,'.');
+	if (!ext)
+	    continue;
+	if (!strncasecmp(ext,".ttf",4) || !strncasecmp(ext, ".ttc", 4))
+	{
+	    dfp = new DisplayFontParam(fontName->copy(), displayFontTT);
+	    dfp->tt.fileName = new GooString((char*)s);
+	}
+	else if (!strncasecmp(ext,".pfa",4) || !strncasecmp(ext,".pfb",4))
+	{
+	    dfp = new DisplayFontParam(fontName->copy(), displayFontT1);
+	    dfp->t1.fileName = new GooString((char*)s);
+	}
+	else
+	    continue;
+	displayFonts->add(dfp->name,dfp);
+	break;
     }
-    else if (!strncasecmp(ext,".pfa",4) || !strncasecmp(ext,".pfb",4)) 
-    {
-      dfp = new DisplayFontParam(fontName->copy(), displayFontT1);  
-      dfp->t1.fileName = new GooString((char*)s);
-    }
-    else
-      goto fin;
-    displayFonts->add(dfp->name,dfp);
+    FcFontSetDestroy(set);
   }
 fin:
-  if (m)
-    FcPatternDestroy(m);
   if (p)
     FcPatternDestroy(p);
 
