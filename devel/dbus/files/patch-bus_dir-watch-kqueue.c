--- bus/dir-watch-kqueue.c
+++ bus/dir-watch-kqueue.c
@@ -139,17 +139,18 @@ out:
 }
 
 void
-bus_set_watched_dir (BusContext *context, DBusList **directories)
+bus_set_watched_dirs (BusContext *context, DBusList **directories)
 {
   int new_fds[MAX_DIRS_TO_WATCH];
   char *new_dirs[MAX_DIRS_TO_WATCH];
   DBusList *link;
-  int i, f, fd;
+  int i, j, f, fd;
+  struct kevent ev;
 
   if (!_init_kqueue (context))
     goto out;
 
-  for (i = 0; i < MAX_DIRS_TO_WATCH; i++) {
+  for (i = 0; i < MAX_DIRS_TO_WATCH; i++)
     {
       new_fds[i] = -1;
       new_dirs[i] = NULL;
@@ -213,7 +214,7 @@ bus_set_watched_dir (BusContext *context
                   NOTE_DELETE | NOTE_EXTEND | NOTE_WRITE | NOTE_RENAME, 0, 0);
           if (kevent (kq, &ev, 1, NULL, 0, NULL) == -1)
             {
-              _dbus_warn ("Cannot setup a kevent for '%s'; error '%s'\n", dir, _dbus_strerror (errno));
+              _dbus_warn ("Cannot setup a kevent for '%s'; error '%s'\n", new_dirs[i], _dbus_strerror (errno));
               close (fd);
               goto out;
             }
