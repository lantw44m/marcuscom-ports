--- mozilla/mozilla-embed.cpp.orig	Sun Oct  3 20:39:54 2004
+++ mozilla/mozilla-embed.cpp	Sun Oct  3 20:45:47 2004
@@ -961,7 +961,7 @@
 
 	
 #if MOZILLA_CHECK_VERSION4 (1,8,MOZILLA_ALPHA,3) || \
-    (MOZILLA_IS_BRANCH (1,7) && MOZILLA_CHECK_VERSION3(1,7,3))
+  (MOZILLA_IS_BRANCH (1,7) && MOZILLA_CHECK_VERSION3(1,7,3))
 	gtk_moz_embed_reload (GTK_MOZ_EMBED(embed), reloadFlags);
 	return G_OK;
 #else
@@ -1388,7 +1388,8 @@
 	rv = wrapper->ForceEncoding (charset);
 	if (NS_FAILED (rv)) return G_FAILED;
 
-#if MOZILLA_CHECK_VERSION4 (1,8,MOZILLA_ALPHA,3)
+#if MOZILLA_CHECK_VERSION4 (1,8,MOZILLA_ALPHA,3) || \
+  (MOZILLA_IS_BRANCH (1,7) && MOZILLA_CHECK_VERSION3(1,7,3))
 	gtk_moz_embed_reload (GTK_MOZ_EMBED (embed),
 			      GTK_MOZ_EMBED_FLAG_RELOADCHARSETCHANGE);
 #else
@@ -1700,10 +1701,8 @@
 	if (NS_SUCCEEDED(rv) &&
 	    ((info->keycode == nsIDOMKeyEvent::DOM_VK_F10 &&
 	      info->modifier == GDK_SHIFT_MASK) 
-#if MOZILLA_CHECK_VERSION4(1,7,MOZILLA_BETA,0)
 	     || (info->keycode == nsIDOMKeyEvent::DOM_VK_CONTEXT_MENU &&
 		 !info->modifier)
-#endif
 		    ))
 	{
 		// Translate relative coordinates to absolute values, and try
