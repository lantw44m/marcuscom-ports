--- gcalctool/ce_parser.y.orig	Mon Jul 26 22:19:27 2004
+++ gcalctool/ce_parser.y	Mon Jul 26 22:25:49 2004
@@ -111,10 +111,12 @@
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
@@ -135,10 +137,12 @@
   initialise();
   show_display(v->MPdisp_val);
 }
+;
 
 value: 
   lexp {cp($1, $$);}
 | exp {cp($1, $$);}
+;
 
 lexp:
   tINUMBER {cp($1, $$);}
@@ -147,6 +151,7 @@
 | lexp tXNOR lexp {calc_xnor($$, $1, $3);}
 | lexp tXOR lexp {calc_xor($$, $1, $3);}
 | '~' lexp {calc_not($2, $$);}
+;
 
 exp: 
   term {cp($1, $$);}
@@ -155,6 +160,7 @@
 
 | exp '+' exp {mpadd($1, $3, $$);}
 | exp '-' exp {mpsub($1, $3, $$);}
+;
 
 term:
   number {cp($1, $$);}
@@ -171,15 +177,18 @@
 
 | parenthesis {cp($1, $$);}
 | constant {cp($1, $$);}
+;
 
 parenthesis:
   '(' exp ')' {cp($2, $$);}
+  ;
 
 reg: 
-  tREG {do_rcl_reg($1, $$)};
+  tREG {do_rcl_reg($1, $$);};
 
 constant:
   'e' {do_e($$);}
+  ;
 
 func:
   tLOG10 term %prec HIGH {mplog10($2, $$);}
@@ -216,6 +225,7 @@
 | tSLN %prec HIGH {calc_sln($$);}
 | tSYD %prec HIGH {calc_syd($$);}
 | tTERM %prec HIGH {calc_term($$);}
+;
 
 rcl:
   tRCL '(' tINUMBER ')' {
@@ -223,11 +233,13 @@
     mpcmi($3, &val);
     do_rcl_reg(val, $$);
   }
+  ;
 
 number:
   tINUMBER {cp($1, $$);}
 | tDNUMBER {cp($1, $$);}
 | tANS {cp(v->e.ans, $$);}
+;
 
 %%
 
