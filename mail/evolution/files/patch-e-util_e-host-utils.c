--- e-util/e-host-utils.c.orig	Thu Sep 30 16:39:55 2004
+++ e-util/e-host-utils.c	Thu Sep 30 16:45:00 2004
@@ -136,12 +136,21 @@
 	case EAI_SERVICE:
 		return NO_DATA;
 		break;
+#ifdef EAI_ADDRFAMILY
 	case EAI_ADDRFAMILY:
 		return NO_ADDRESS;
 		break;
+#endif
+#ifdef EAI_NODATA
 	case EAI_NODATA:
 		return NO_DATA;
 		break;
+#endif
+#ifdef EAI_NOFAMILY
+	case EAI_NOFAMILY:
+		return NO_ADDRESS;
+		break;
+#endif
 	case EAI_MEMORY:
 		return ENOMEM;
 		break;
