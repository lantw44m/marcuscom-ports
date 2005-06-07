--- providers/mysql/gda-mysql-recordset.c.orig	Tue Jun  7 16:23:21 2005
+++ providers/mysql/gda-mysql-recordset.c	Tue Jun  7 16:24:00 2005
@@ -615,6 +615,7 @@ gda_mysql_recordset_remove_row (GdaDataM
 	     colnum != gda_data_model_get_n_columns (GDA_DATA_MODEL(model));
 	     colnum++)
 	{
+		gchar *curval;
 		attrs = gda_data_model_describe_column (GDA_DATA_MODEL(model), colnum);
 
 		mysql_field = mysql_fetch_field_direct (priv_data->mysql_res, colnum);
@@ -623,7 +624,7 @@ gda_mysql_recordset_remove_row (GdaDataM
 		else
 			column_name = gda_data_model_get_column_title (GDA_DATA_MODEL (model), colnum);
 
-		gchar *curval = gda_mysql_provider_value_to_sql_string (
+		curval = gda_mysql_provider_value_to_sql_string (
 				NULL, 	 
 				priv_data->cnc, 	 
 				gda_row_get_value ((GdaRow *) row, colnum) 	 
@@ -900,11 +901,11 @@ gda_mysql_recordset_new (GdaConnection *
 		gda_data_model_array_set_n_columns (GDA_DATA_MODEL_ARRAY (model),
 					    model->priv->ncolumns);
 		for (i = 0; i < model->priv->ncolumns; i++) {
+			gboolean multi_table = FALSE;
 			gda_data_model_set_column_title (GDA_DATA_MODEL (model),
 							 i, mysql_fields[i].name);
 
 			/* determine table name */
-			gboolean multi_table = FALSE;
 			if (strcmp(mysql_fields[i].table, mysql_fields[0].table) != 0)
 				multi_table = TRUE;
 
