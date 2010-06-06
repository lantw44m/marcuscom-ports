--- girepository/ginfo.c.orig	2010-06-01 21:48:36.000000000 +0200
+++ girepository/ginfo.c	2010-06-06 12:13:50.000000000 +0200
@@ -29,6 +29,9 @@
 #include "ginfo.h"
 #include "girepository-private.h"
 
+#define DO_ALIGNED_COPY(dest_addr, src_addr, type) \
+	memcpy((dest_addr), (src_addr), sizeof(type))
+
 /* GICallableInfo functions */
 
 /**
@@ -2148,16 +2151,16 @@ g_constant_info_get_value (GIConstantInf
 	      value->v_uint32 = *(guint32*)&rinfo->typelib->data[blob->offset];
 	      break;
 	    case GI_TYPE_TAG_INT64:
-	      value->v_int64 = *(gint64*)&rinfo->typelib->data[blob->offset];
+	      DO_ALIGNED_COPY(&value->v_int64, &rinfo->typelib->data[blob->offset], gint64);
 	      break;
 	    case GI_TYPE_TAG_UINT64:
-	      value->v_uint64 = *(guint64*)&rinfo->typelib->data[blob->offset];
+	      DO_ALIGNED_COPY(&value->v_uint64, &rinfo->typelib->data[blob->offset], guint64);
 	      break;
 	    case GI_TYPE_TAG_FLOAT:
-	      value->v_float = *(gfloat*)&rinfo->typelib->data[blob->offset];
+	      DO_ALIGNED_COPY(&value->v_float, &rinfo->typelib->data[blob->offset], gfloat);
 	      break;
 	    case GI_TYPE_TAG_DOUBLE:
-	      value->v_double = *(gdouble*)&rinfo->typelib->data[blob->offset];
+	      DO_ALIGNED_COPY(&value->v_double, &rinfo->typelib->data[blob->offset], gdouble);
 	      break;
 	    case GI_TYPE_TAG_TIME_T:
 	      value->v_long = *(long*)&rinfo->typelib->data[blob->offset];
@@ -2175,10 +2178,10 @@ g_constant_info_get_value (GIConstantInf
 	      value->v_uint = *(guint*)&rinfo->typelib->data[blob->offset];
 	      break;
 	    case GI_TYPE_TAG_LONG:
-	      value->v_long = *(glong*)&rinfo->typelib->data[blob->offset];
+	      DO_ALIGNED_COPY(&value->v_long, &rinfo->typelib->data[blob->offset], glong);
 	      break;
 	    case GI_TYPE_TAG_ULONG:
-	      value->v_ulong = *(gulong*)&rinfo->typelib->data[blob->offset];
+	      DO_ALIGNED_COPY(&value->v_ulong, &rinfo->typelib->data[blob->offset], gulong);
 	      break;
 	    }
 	}
