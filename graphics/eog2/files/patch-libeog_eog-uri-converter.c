--- libeog/eog-uri-converter.c.orig	Thu Jul 22 16:40:16 2004
+++ libeog/eog-uri-converter.c	Thu Jul 22 16:44:59 2004
@@ -20,7 +20,7 @@
 	union {
 		char    *string;  /* if type == EOG_UC_STRING */
 		gulong  counter;  /* if type == EOG_UC_COUNTER */
-	};
+	} data;
 } EogUCToken;
 
 
@@ -64,8 +64,8 @@
 {
 	EogUCToken *token = (EogUCToken*) data;
 
-	if (token->type == EOG_UC_STRING && token->string != NULL) {
-		g_free (token->string);
+	if (token->type == EOG_UC_STRING && token->data.string != NULL) {
+		g_free (token->data.string);
 	}
 
 	g_free (token);
@@ -321,8 +321,8 @@
 
 	token = g_new0 (EogUCToken, 1);
 	token->type = EOG_UC_STRING;
-	token->string = g_new0 (char, n_bytes);
-	token->string = g_utf8_strncpy (token->string, start_byte, substr_len);
+	token->data.string = g_new0 (char, n_bytes);
+	token->data.string = g_utf8_strncpy (token->data.string, start_byte, substr_len);
 	
 	return token;
 }
@@ -334,7 +334,7 @@
 
 	token = g_new0 (EogUCToken, 1);
 	token->type = EOG_UC_COUNTER;
-	token->counter = 0;
+	token->data.counter = 0;
 
 	return token;
 }
@@ -488,13 +488,13 @@
 		
 		switch (token->type) {
 		case EOG_UC_STRING:
-			str = g_strdup_printf ("string [%s]", token->string);
+			str = g_strdup_printf ("string [%s]", token->data.string);
 			break;
 		case EOG_UC_FILENAME:
 			str = "filename";
 			break;
 		case EOG_UC_COUNTER:
-			str = g_strdup_printf ("counter [%li]", token->counter);
+			str = g_strdup_printf ("counter [%li]", token->data.counter);
 			break;
 		case EOG_UC_COMMENT:
 			str = "comment";
@@ -785,7 +785,7 @@
 
 		switch (token->type) {
 		case EOG_UC_STRING:
-			str = g_string_append (str, token->string);
+			str = g_string_append (str, token->data.string);
 			break;
 
 		case EOG_UC_FILENAME:
@@ -793,10 +793,10 @@
 			break;
 
 		case EOG_UC_COUNTER: {
-			if (token->counter < priv->counter_start) 
-				token->counter = priv->counter_start;
+			if (token->data.counter < priv->counter_start) 
+				token->data.counter = priv->counter_start;
 			
-			str = append_counter (str, token->counter++, conv);
+			str = append_counter (str, token->data.counter++, conv);
 			break;
 		}
 #if 0
