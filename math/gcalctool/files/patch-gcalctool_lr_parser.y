--- gcalctool/lr_parser.y.orig	Mon Jul 26 22:23:06 2004
+++ gcalctool/lr_parser.y	Mon Jul 26 22:26:34 2004
@@ -107,10 +107,12 @@
   parser_state.error = EINVAL; 
   YYABORT;
 }
+;
 
 seq:
   udf
 | seq udf
+;
 
 udf:
   value '=' {
@@ -131,9 +133,11 @@
   initialise();
   show_display(v->MPdisp_val);
 }
+;
 
 value:
   exp {cp($1, $$);}
+  ;
 
 exp: 
   term {cp($1, $$);}
@@ -164,10 +168,11 @@
 | exp '~' {calc_not($1, $$);}
 | exp ']' {calc_u16($1, $$);}
 | exp '[' {calc_u32($1, $$);}
-| exp '}' {calc_tenpowx($1, $$)}
-| exp '{' {mpexp($1, $$)}
+| exp '}' {calc_tenpowx($1, $$);}
+| exp '{' {mpexp($1, $$);}
 
 | func {cp($1, $$);}
+;
 
 func:
   tLOG10 parenthesis {mplog10($2, $$);}
@@ -188,9 +193,11 @@
 | term tCOS {calc_trigfunc(cos_t, $1, $$);}
 | tTAN parenthesis {calc_trigfunc(tan_t, $2, $$);}
 | term tTAN {calc_trigfunc(tan_t, $1, $$);}
+;
 
 parenthesis:
   '(' exp ')' {cp($2, $$);}
+  ;
 
 term:
   number {cp($1, $$);}
@@ -198,6 +205,7 @@
 | parenthesis {cp($1, $$);}
 | '-' term %prec POS {mpneg($2, $$);}
 | '+' term %prec POS {cp($2, $$);}
+;
 
 rcl:
   tRCL '(' tINUMBER ')' {
@@ -205,10 +213,12 @@
     mpcmi($3, &val);
     do_rcl_reg(val, $$);
   }
+  ;
 
 number:
   tINUMBER {cp($1, $$);}
 | tDNUMBER {cp($1, $$);}
+;
 
 %%
 
