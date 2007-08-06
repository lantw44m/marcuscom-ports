--- deskbar/handlers/evolution/evolution.c.orig	2007-08-06 13:04:33.000000000 -0400
+++ deskbar/handlers/evolution/evolution.c	2007-08-06 13:07:35.000000000 -0400
@@ -220,7 +220,6 @@ init (void)
 					books = g_slist_prepend (books, book);
 					e_book_open(book, TRUE, NULL);
 				}
-				g_free (uri);
 			}
 		}
 	}
