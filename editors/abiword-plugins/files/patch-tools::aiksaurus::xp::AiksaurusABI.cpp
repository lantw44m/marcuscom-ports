--- tools/aiksaurus/xp/AiksaurusABI.cpp.orig	Sun Jun 15 07:09:42 2003
+++ tools/aiksaurus/xp/AiksaurusABI.cpp	Fri Jul 23 12:19:18 2004
@@ -310,13 +310,13 @@
     pView->extSelTo(FV_DOCPOS_EOW_SELECT);  
 	
     // Now we will figure out what word to look up when we open our dialog.
-    char* search = "";
+    char* search = NULL;
     if (!pView->isSelectionEmpty())
     {
         // We need to get the Ascii version of the current word.
-        search = AiksaurusABI_ucsToAscii(
-					 pView->getSelectionText()
-        );
+        UT_UCS4Char *ucs4ST;
+        pView->getSelectionText(*&ucs4ST);
+        search = AiksaurusABI_ucsToAscii(ucs4ST);
     }
 
     // Now we will run the thesaurus dialog and get a response.
