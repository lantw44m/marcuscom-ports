--- libseed/seed-types.c.orig	2010-07-13 11:29:42.000000000 +0200
+++ libseed/seed-types.c	2010-07-13 11:31:26.000000000 +0200
@@ -366,23 +366,6 @@
 	*array_p = dblresult;
       }
       break;
-    case GI_TYPE_TAG_INT:
-      {
-	gint *intresult;
-
-	intresult = g_new0 (gint, length + 1);
-
-	for (i = 0; i < length; i++)
-	  {
-	    elem = JSObjectGetPropertyAtIndex (ctx,
-					       (JSObjectRef) array,
-					       i, exception);
-	    intresult[i] = seed_value_to_int (ctx, elem, exception);
-	  }
-
-	*array_p = intresult;
-      }
-      break;
     case GI_TYPE_TAG_UINT8:
       {
 	guint8 *guint8result;
@@ -492,30 +475,12 @@
     case GI_TYPE_TAG_UINT32:
       arg->v_uint32 = seed_value_to_uint (ctx, value, exception);
       break;
-    case GI_TYPE_TAG_LONG:
-      arg->v_long = seed_value_to_long (ctx, value, exception);
-      break;
     case GI_TYPE_TAG_INT64:
       arg->v_int64 = seed_value_to_int64 (ctx, value, exception);
       break;
-    case GI_TYPE_TAG_ULONG:
-      arg->v_ulong = seed_value_to_ulong (ctx, value, exception);
-      break;
     case GI_TYPE_TAG_UINT64:
       arg->v_uint64 = seed_value_to_uint64 (ctx, value, exception);
       break;
-    case GI_TYPE_TAG_INT:
-      arg->v_int = seed_value_to_int (ctx, value, exception);
-      break;
-    case GI_TYPE_TAG_UINT:
-      arg->v_uint = seed_value_to_uint (ctx, value, exception);
-      break;
-    case GI_TYPE_TAG_SIZE:
-      arg->v_size = seed_value_to_size (ctx, value, exception);
-      break;
-    case GI_TYPE_TAG_SSIZE:
-      arg->v_ssize = seed_value_to_ssize (ctx, value, exception);
-      break;
     case GI_TYPE_TAG_FLOAT:
       arg->v_float = seed_value_to_float (ctx, value, exception);
       break;
@@ -531,9 +496,6 @@
     case GI_TYPE_TAG_GTYPE:
       arg->v_int = seed_value_to_int (ctx, value, exception);
       break;
-    case GI_TYPE_TAG_TIME_T:
-      arg->v_long = seed_value_to_time_t (ctx, value, exception);
-      break;
     case GI_TYPE_TAG_INTERFACE:
       {
 	GIBaseInfo *interface;
@@ -774,22 +736,10 @@
       return seed_value_from_int (ctx, arg->v_int32, exception);
     case GI_TYPE_TAG_UINT32:
       return seed_value_from_uint (ctx, arg->v_uint32, exception);
-    case GI_TYPE_TAG_LONG:
-      return seed_value_from_long (ctx, arg->v_long, exception);
     case GI_TYPE_TAG_INT64:
       return seed_value_from_int64 (ctx, arg->v_int64, exception);
-    case GI_TYPE_TAG_ULONG:
-      return seed_value_from_ulong (ctx, arg->v_ulong, exception);
     case GI_TYPE_TAG_UINT64:
       return seed_value_from_uint64 (ctx, arg->v_uint64, exception);
-    case GI_TYPE_TAG_INT:
-      return seed_value_from_int (ctx, arg->v_int32, exception);
-    case GI_TYPE_TAG_UINT:
-      return seed_value_from_uint (ctx, arg->v_uint32, exception);
-    case GI_TYPE_TAG_SSIZE:
-      return seed_value_from_ssize (ctx, arg->v_ssize, exception);
-    case GI_TYPE_TAG_SIZE:
-      return seed_value_from_size (ctx, arg->v_size, exception);
     case GI_TYPE_TAG_FLOAT:
       return seed_value_from_float (ctx, arg->v_float, exception);
     case GI_TYPE_TAG_DOUBLE:
@@ -800,8 +750,6 @@
       return seed_value_from_filename (ctx, arg->v_string, exception);
     case GI_TYPE_TAG_GTYPE:
       return seed_value_from_int (ctx, arg->v_int, exception);
-    case GI_TYPE_TAG_TIME_T:
-      return seed_value_from_time_t (ctx, arg->v_long, exception);
     case GI_TYPE_TAG_ARRAY:
       {
 	GITypeInfo *param_type;
