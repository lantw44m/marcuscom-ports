--- providers/xml/gda-xml-provider.c.orig	Sat Aug 14 12:41:57 2004
+++ providers/xml/gda-xml-provider.c	Sat Aug 14 12:43:17 2004
@@ -652,33 +652,32 @@
 	/* create the recordset */
 	recset = GDA_DATA_MODEL_ARRAY (gda_data_model_array_new (4));
 	gda_data_model_set_column_title (GDA_DATA_MODEL (recset), 0, _("Type"));
-	gda_data_model_set_column_title (GDA_DATA_MODEL (recset), 0, _("Type"));
 	gda_data_model_set_column_title (GDA_DATA_MODEL (recset), 1, _("Owner"));
 	gda_data_model_set_column_title (GDA_DATA_MODEL (recset), 2, _("Comments"));
 	gda_data_model_set_column_title (GDA_DATA_MODEL (recset), 3, _("GDA type"));
 
 	/* fill the recordset */
-	add_type_row (recset, "bigint", NULL, _("Big integer"), GDA_VALUE_TYPE_BIGINT);
-	add_type_row (recset, "biguint", NULL, _("Big unsigned integer"), GDA_VALUE_TYPE_BIGUINT);
-	add_type_row (recset, "binary", NULL, _("Binary"), GDA_VALUE_TYPE_BINARY);
-	add_type_row (recset, "boolean", NULL, _("Boolean"), GDA_VALUE_TYPE_BOOLEAN);
-	add_type_row (recset, "date", NULL, _("Date"), GDA_VALUE_TYPE_DATE);
-	add_type_row (recset, "double", NULL, _("Double precision"), GDA_VALUE_TYPE_DOUBLE);
-	add_type_row (recset, "integer", NULL, _("Integer"), GDA_VALUE_TYPE_INTEGER);
-	add_type_row (recset, "list", NULL, _("List"), GDA_VALUE_TYPE_LIST);
-	add_type_row (recset, "money", NULL, _("Money"), GDA_VALUE_TYPE_MONEY);
-	add_type_row (recset, "numeric", NULL, _("Numeric"), GDA_VALUE_TYPE_NUMERIC);
-	add_type_row (recset, "point", NULL, _("Point"), GDA_VALUE_TYPE_GEOMETRIC_POINT);
-	add_type_row (recset, "single", NULL, _("Single precision"), GDA_VALUE_TYPE_SINGLE);
-	add_type_row (recset, "smallint", NULL, _("Small integer"), GDA_VALUE_TYPE_SMALLINT);
-	add_type_row (recset, "smalluint", NULL, _("Small unsigned integer"), GDA_VALUE_TYPE_SMALLUINT);
-	add_type_row (recset, "string", NULL, _("String"), GDA_VALUE_TYPE_STRING);
-	add_type_row (recset, "time", NULL, _("Time"), GDA_VALUE_TYPE_TIME);
-	add_type_row (recset, "timestamp", NULL, _("Timestamp"), GDA_VALUE_TYPE_TIMESTAMP);
-	add_type_row (recset, "tinyint", NULL, _("Tiny integer"), GDA_VALUE_TYPE_TINYINT);
-	add_type_row (recset, "tinyuint", NULL, _("Tiny unsigned integer"), GDA_VALUE_TYPE_TINYUINT);
-	add_type_row (recset, "type", NULL, _("Type"), GDA_VALUE_TYPE_TYPE);
-	add_type_row (recset, "uinteger", NULL, _("Unsigned integer"), GDA_VALUE_TYPE_UINTEGER);
+	add_type_row (recset, "bigint", "", _("Big integer"), GDA_VALUE_TYPE_BIGINT);
+	add_type_row (recset, "biguint", "", _("Big unsigned integer"), GDA_VALUE_TYPE_BIGUINT);
+	add_type_row (recset, "binary", "", _("Binary"), GDA_VALUE_TYPE_BINARY);
+	add_type_row (recset, "boolean", "", _("Boolean"), GDA_VALUE_TYPE_BOOLEAN);
+	add_type_row (recset, "date", "", _("Date"), GDA_VALUE_TYPE_DATE);
+	add_type_row (recset, "double", "", _("Double precision"), GDA_VALUE_TYPE_DOUBLE);
+	add_type_row (recset, "integer", "", _("Integer"), GDA_VALUE_TYPE_INTEGER);
+	add_type_row (recset, "list", "", _("List"), GDA_VALUE_TYPE_LIST);
+	add_type_row (recset, "money", "", _("Money"), GDA_VALUE_TYPE_MONEY);
+	add_type_row (recset, "numeric", "", _("Numeric"), GDA_VALUE_TYPE_NUMERIC);
+	add_type_row (recset, "point", "", _("Point"), GDA_VALUE_TYPE_GEOMETRIC_POINT);
+	add_type_row (recset, "single", "", _("Single precision"), GDA_VALUE_TYPE_SINGLE);
+	add_type_row (recset, "smallint", "", _("Small integer"), GDA_VALUE_TYPE_SMALLINT);
+	add_type_row (recset, "smalluint", "", _("Small unsigned integer"), GDA_VALUE_TYPE_SMALLUINT);
+	add_type_row (recset, "string", "", _("String"), GDA_VALUE_TYPE_STRING);
+	add_type_row (recset, "time", "", _("Time"), GDA_VALUE_TYPE_TIME);
+	add_type_row (recset, "timestamp", "", _("Timestamp"), GDA_VALUE_TYPE_TIMESTAMP);
+	add_type_row (recset, "tinyint", "", _("Tiny integer"), GDA_VALUE_TYPE_TINYINT);
+	add_type_row (recset, "tinyuint", "", _("Tiny unsigned integer"), GDA_VALUE_TYPE_TINYUINT);
+	add_type_row (recset, "type", "", _("Type"), GDA_VALUE_TYPE_TYPE);
+	add_type_row (recset, "uinteger", "", _("Unsigned integer"), GDA_VALUE_TYPE_UINTEGER);
 
 	return GDA_DATA_MODEL (recset);
 }
