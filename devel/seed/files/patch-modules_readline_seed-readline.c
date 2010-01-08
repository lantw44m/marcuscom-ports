--- modules/readline/seed-readline.c.orig	2010-01-07 19:06:34.000000000 -0500
+++ modules/readline/seed-readline.c	2010-01-07 19:01:19.000000000 -0500
@@ -177,7 +177,8 @@ seed_static_function readline_funcs[] = 
 	{"bind", seed_readline_bind, 0},
 	{"done", seed_rl_done, 0},
 	{"buffer", seed_rl_buffer, 0},
-	{"insert", seed_rl_insert, 0}
+	{"insert", seed_rl_insert, 0},
+	{NULL, NULL, 0}
 };
 
 SeedObject
