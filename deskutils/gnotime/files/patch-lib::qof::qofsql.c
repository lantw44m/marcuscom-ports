--- lib/qof/qofsql.c.orig	Tue Apr 20 23:45:10 2004
+++ lib/qof/qofsql.c	Mon May 24 20:33:10 2004
@@ -155,8 +155,9 @@
 	if (('\'' == str[0]) ||
 	    ('\"' == str[0]))
 	{
+		size_t len;
 		str ++;
-		size_t len = strlen(str);
+		len = strlen(str);
 		str[len-1] = 0;
 	}
 	return str;
@@ -168,6 +169,15 @@
 	char tmpbuff[128];
 	GSList *param_list;
 	QofQueryPredData *pred_data = NULL;
+	char * qvalue_name;
+	sql_field_item * sparam;
+	sql_field_item * svalue;
+	char * qparam_name;
+	QofQueryCompare qop;
+	char *table_name;
+	char *param_name;
+	QofType param_type;
+	QofQuery *qq;
 	
 	if (NULL == cond)
 	{
@@ -183,14 +193,14 @@
 		PWARN("missing left paramter");
 		return NULL;
 	}
-	sql_field_item * sparam = cond->d.pair.left->item;
+	sparam = cond->d.pair.left->item;
 	if (SQL_name != sparam->type)
 	{
 		PWARN("we support only paramter names at this time (parsed %d)",
           sparam->type);
 		return NULL;
 	}
-	char * qparam_name = sparam->d.name->data;
+	qparam_name = sparam->d.name->data;
 	if (NULL == qparam_name)
 	{
 		PWARN ("missing paramter name");
@@ -205,13 +215,13 @@
 		PWARN ("missing right paramter");
 		return NULL;
 	}
-	sql_field_item * svalue = cond->d.pair.right->item;
+	svalue = cond->d.pair.right->item;
 	if (SQL_name != svalue->type)
 	{
 		PWARN("we support only simple values (parsed as %d)", svalue->type);
 		return NULL;
 	}
-	char * qvalue_name = svalue->d.name->data;
+	qvalue_name = svalue->d.name->data;
 	if (NULL == qvalue_name)
 	{
 		PWARN("missing value");
@@ -224,16 +234,18 @@
 	 * If it is, look up the value. */
 	if (0 == strncasecmp (qvalue_name, "kvp://", 6))
 	{
+		KvpValue *kv;
+		KvpValueType kvt;
 		if (NULL == query->kvp_join)
 		{
 			PWARN ("missing kvp frame");
 			return NULL;
 		}
-		KvpValue *kv = kvp_frame_get_value (query->kvp_join, qvalue_name+5);
+		kv = kvp_frame_get_value (query->kvp_join, qvalue_name+5);
 		/* If there's no value, its not an error; 
 		 * we just don't do this predicate */
 		if (!kv) return NULL;  
-		KvpValueType kvt = kvp_value_get_type (kv);
+		kvt = kvp_value_get_type (kv);
 
 		tmpbuff[0] = 0x0;
 		qvalue_name = tmpbuff;
@@ -273,7 +285,6 @@
 	param_list = qof_query_build_param_list (qparam_name, NULL);
 
 	/* Get the where-term comparison operator */
-	QofQueryCompare qop;
 	switch (cond->op)
 	{
 		case SQL_eq:    qop = QOF_COMPARE_EQUAL; break;
@@ -292,8 +303,6 @@
 	/* OK, need to know the type of the thing being matched 
 	 * in order to build the correct predicate.  Get the type 
 	 * from the object parameters. */
-	char *table_name;
-	char *param_name;
 	get_table_and_param (qparam_name, &table_name, &param_name);
 	if (NULL == table_name)
 	{
@@ -306,7 +315,7 @@
 		return NULL;
 	}
 			
-	QofType param_type = qof_class_get_parameter_type (table_name, param_name);
+	param_type = qof_class_get_parameter_type (table_name, param_name);
 	if (!param_type) return NULL;  /* Can't happen */
 
 	if (!strcmp (param_type, QOF_TYPE_STRING))
@@ -328,7 +337,7 @@
 	}
 	else if (!strcmp (param_type, QOF_TYPE_INT64))
 	{
-		gint64 ival = atoll (qvalue_name);
+		gint64 ival = atol (qvalue_name);
 		pred_data = qof_query_int64_predicate (qop, ival);
 	}
 	else if (!strcmp (param_type, QOF_TYPE_DOUBLE))
@@ -346,16 +355,17 @@
 		// XXX FIXME: this doesn't handle time strings, only date strings
 		// XXX should also see if we need to do a day-compare or time-compare.
 		/* work around highly bogus locale setting */
+		time_t exact;
+		int rc;
+		Timespec ts;
 		qof_date_format_set(QOF_DATE_FORMAT_US);
 
-		time_t exact;
-		int rc = qof_scan_date_secs (qvalue_name, &exact);
+		rc = qof_scan_date_secs (qvalue_name, &exact);
 		if (0 == rc) 
 		{
 			PWARN ("unable to parse date: %s", qvalue_name);
 			return NULL;
 		}
-		Timespec ts;
 		ts.tv_sec = exact;
 		ts.tv_nsec = 0;
 		pred_data = qof_query_date_predicate (qop, QOF_DATE_MATCH_DAY, ts);
@@ -375,8 +385,11 @@
 	}
 	else if (!strcmp (param_type, QOF_TYPE_GUID))
 	{
-		GUID *guid = guid_malloc();
-		gboolean rc = string_to_guid (qvalue_name, guid);
+		GUID *guid;
+		gboolean rc;
+		GList *guid_list;
+		guid = guid_malloc();
+		rc = string_to_guid (qvalue_name, guid);
 		if (0 == rc)
 		{
 			PWARN ("unable to parse guid: %s", qvalue_name);
@@ -386,7 +399,7 @@
 		// XXX match any means eqal, what about not equal ?? 
 		// XXX less, than greater than don't make sense,
 		// should check for those bad conditions
-		GList *guid_list = g_list_append (NULL, guid);
+		guid_list = g_list_append (NULL, guid);
 		pred_data = qof_query_guid_predicate (QOF_GUID_MATCH_ANY, guid_list);
 		// XXX FIXME the above is a memory leak! we leak both guid and glist.
 	}
@@ -404,7 +417,7 @@
 		return NULL;
 	}
 
-	QofQuery *qq = qof_query_create();
+	qq = qof_query_create();
 	qof_query_add_term (qq, param_list, pred_data, QOF_QUERY_FIRST_TERM);
 	return qq;
 }
@@ -418,11 +431,12 @@
 	{
 		case SQL_pair:
 		{
+			QofQueryOp qop;
+			QofQuery * qq;
 			QofQuery *qleft = handle_where (query, swear->d.pair.left);
 			QofQuery *qright = handle_where (query, swear->d.pair.right);
 			if (NULL == qleft) return qright;
 			if (NULL == qright) return qleft;
-			QofQueryOp qop;
 			switch (swear->d.pair.op)
 			{
 				case SQL_and: qop = QOF_QUERY_AND; break;
@@ -433,7 +447,7 @@
 					qof_query_destroy (qright);
 					return NULL;
 			}
-			QofQuery * qq = qof_query_merge (qleft, qright, qop);
+			qq = qof_query_merge (qleft, qright, qop);
 			qof_query_destroy (qleft);
 			qof_query_destroy (qright);
 			return qq;
@@ -460,12 +474,12 @@
 static void 
 handle_sort_order (QofSqlQuery *query, GList *sorder_list)
 {
-	if (!sorder_list) return;
-
 	GSList *qsp[3];
 	gboolean direction[3];
 	int i;
 
+	if (!sorder_list) return;
+
 	for (i=0; i<3; i++)
 	{
 		qsp[i] = NULL;
@@ -474,13 +488,13 @@
 		if (sorder_list)
 		{
 			sql_order_field *sorder = sorder_list->data;
+			char * qparam_name = NULL;
+			GList *n = sorder->name;
 
 			/* Set the sort direction */
 			if (SQL_asc == sorder->order_type) direction[i] = TRUE;
 
 			/* Find the paramter name */
-			char * qparam_name = NULL;
-			GList *n = sorder->name;
 			if (n)
 			{
 				qparam_name = n->data;
@@ -509,6 +523,10 @@
 qof_sql_query_run (QofSqlQuery *query, const char *str)
 {
 	GList *node;
+	GList *tables;
+	GList *results;
+	sql_select_statement *sss;
+	sql_where * swear;
 
 	if (!query) return NULL;
 	query->parse_result = sql_parse (str);
@@ -531,14 +549,14 @@
 	 * user wrote "SELECT * FROM tableA, tableB WHERE ..."
 	 * then we don't have a single unique table-name.
 	 */
-	GList *tables = sql_statement_get_tables (query->parse_result);
+	tables = sql_statement_get_tables (query->parse_result);
 	if (1 == g_list_length (tables))
 	{
 		query->single_global_tablename = tables->data;
 	}
 
-	sql_select_statement *sss = query->parse_result->statement;
-	sql_where * swear = sss->where;
+	sss = query->parse_result->statement;
+	swear = sss->where;
 	if (swear)
 	{
 		/* Walk over the where terms, turn them into QOF predicates */
@@ -562,7 +580,7 @@
 	qof_query_set_book (query->qof_query, query->book);
 
 	// qof_query_print (query->qof_query);
-	GList *results = qof_query_run (query->qof_query);
+	results = qof_query_run (query->qof_query);
 
 	return results;
 }
