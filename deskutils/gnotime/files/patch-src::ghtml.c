--- src/ghtml.c.orig	Mon May 24 20:14:28 2004
+++ src/ghtml.c	Mon May 24 20:15:57 2004
@@ -163,8 +163,9 @@
 			type = SCM_CDR (node);
 			if (SCM_SYMBOLP(type) || SCM_STRINGP (type))
 			{
+				char *buff;
 				cur_type = GTT_NONE;
-				char *buff = SCM_STRING_CHARS (type);
+				buff = SCM_STRING_CHARS (type);
 
 				if ((!strncmp (buff, "gtt-project-ptr",15)) ||
 				    (!strncmp (buff, "gtt-project-list",16)))
@@ -1181,6 +1182,9 @@
 static SCM 
 my_catch_handler (void *data, SCM tag, SCM throw_args)
 {
+	SCM fmt;
+	SCM s_str;
+
 	printf ("Error: GnoTime caught error during scheme parse\n");
 	if (SCM_SYMBOLP(tag))
 	{
@@ -1189,8 +1193,8 @@
 	}
 	scm_backtrace(); 
 
-	SCM fmt = scm_makfrom0str ("~S");
-	SCM s_str = scm_simple_format (SCM_BOOL_F, fmt, SCM_LIST1(throw_args));
+	fmt = scm_makfrom0str ("~S");
+	s_str = scm_simple_format (SCM_BOOL_F, fmt, SCM_LIST1(throw_args));
 	printf ("\tthrow_args=%s\n", SCM_STRING_CHARS (s_str));
 
 	return SCM_EOL;
