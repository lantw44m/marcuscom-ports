--- girepository/giconstantinfo.c.orig	2010-09-06 13:15:38.000000000 -0400
+++ girepository/giconstantinfo.c	2010-09-06 13:17:33.000000000 -0400
@@ -64,6 +64,9 @@ g_constant_info_get_type (GIConstantInfo
   return _g_type_info_new ((GIBaseInfo*)info, rinfo->typelib, rinfo->offset + 8);
 }
 
+#define DO_ALIGNED_COPY(dest_addr, src_addr, type) \
+        memcpy((dest_addr), (src_addr), sizeof(type))
+
 /**
  * g_constant_info_get_value:
  * @info: a #GIConstantInfo
@@ -118,16 +121,16 @@ g_constant_info_get_value (GIConstantInf
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
 	    }
 	}
