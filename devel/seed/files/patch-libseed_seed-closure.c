--- libseed/seed-closure.c.orig	2010-07-13 11:25:23.000000000 +0200
+++ libseed/seed-closure.c	2010-07-13 11:28:30.000000000 +0200
@@ -97,30 +97,12 @@
 	case GI_TYPE_TAG_UINT32:
 	  arg->v_uint32 = *(guint32 *) args[i];
 	  break;
-	case GI_TYPE_TAG_LONG:
-	  arg->v_long = *(glong *) args[i];
-	  break;
 	case GI_TYPE_TAG_INT64:
 	  arg->v_int64 = *(gint64 *) args[i];
 	  break;
-	case GI_TYPE_TAG_ULONG:
-	  arg->v_ulong = *(gulong *) args[i];
-	  break;
 	case GI_TYPE_TAG_UINT64:
 	  arg->v_uint64 = *(guint64 *) args[i];
 	  break;
-	case GI_TYPE_TAG_INT:
-	  arg->v_int = *(gint *) args[i];
-	  break;
-	case GI_TYPE_TAG_SSIZE:
-	  arg->v_ssize = *(gssize *) args[i];
-	  break;
-	case GI_TYPE_TAG_SIZE:
-	  arg->v_size = *(gsize *) args[i];
-	  break;
-	case GI_TYPE_TAG_UINT:
-	  arg->v_uint = *(guint *) args[i];
-	  break;
 	case GI_TYPE_TAG_FLOAT:
 	  arg->v_float = *(gfloat *) args[i];
 	  break;
@@ -215,30 +197,12 @@
     case GI_TYPE_TAG_UINT32:
       *(guint32 *) result = return_arg.v_uint32;
       break;
-    case GI_TYPE_TAG_LONG:
-      *(glong *) result = return_arg.v_long;
-      break;
     case GI_TYPE_TAG_INT64:
       *(gint64 *) result = return_arg.v_int64;
       break;
-    case GI_TYPE_TAG_ULONG:
-      *(gulong *) result = return_arg.v_ulong;
-      break;
     case GI_TYPE_TAG_UINT64:
       *(guint64 *) result = return_arg.v_uint64;
       break;
-    case GI_TYPE_TAG_INT:
-      *(gint *) result = return_arg.v_int;
-      break;
-    case GI_TYPE_TAG_SSIZE:
-      *(gssize *) result = return_arg.v_ssize;
-      break;
-    case GI_TYPE_TAG_SIZE:
-      *(gsize *) result = return_arg.v_size;
-      break;
-    case GI_TYPE_TAG_UINT:
-      *(guint *) result = return_arg.v_uint;
-      break;
     case GI_TYPE_TAG_FLOAT:
       *(gfloat *) result = return_arg.v_float;
       break;
