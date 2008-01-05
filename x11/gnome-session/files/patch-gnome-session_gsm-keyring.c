Index: gnome-session/gsm-keyring.c
===================================================================
--- gnome-session/gsm-keyring.c	(revision 4516)
+++ gnome-session/gsm-keyring.c	(working copy)
@@ -53,10 +53,10 @@
 {
   GError *err;
   char *standard_out;
-  char **lines;
+  char **lines, **l;
   int status;
   long pid;
-  char *pid_str, *end;
+  char *t, *end;
   const char *old_keyring;
   const char *display;
   char *argv[2];
@@ -100,22 +100,26 @@
 	  WEXITSTATUS (status) == 0 &&
 	  standard_out != NULL)
         {
-	  lines = g_strsplit (standard_out, "\n", 3);
+	  lines = g_strsplit (standard_out, "\n", 0);
+	  for (l = lines; *l; ++l)
+	    {
+	      /* Split the line into name=value */
+	      t = strchr (*l, '=');
+	      if (!t)
+		continue;
+	      *(t++) = 0;
 
-	  if (lines[0] != NULL &&
-	      lines[1] != NULL &&
-	      g_str_has_prefix (lines[1], "GNOME_KEYRING_PID="))
-	    {
-	      pid_str = lines[1] + strlen ("GNOME_KEYRING_PID=");
-	      pid = strtol (pid_str, &end, 10);
-	      if (end != pid_str)
+	      /* Everything that comes out should be an env var */
+	      g_setenv (*l, t, TRUE);
+
+	      /* Track the daemon's PID */
+	      if (g_str_equal (*l, "GNOME_KEYRING_PID")) 
 		{
-		  gnome_keyring_daemon_pid = pid;
-		  g_setenv ("GNOME_KEYRING_SOCKET",
-			    lines[0] + strlen ("GNOME_KEYRING_SOCKET="), TRUE);
+		  pid = strtol (t, &end, 10);
+		  if (end != t)
+		      gnome_keyring_daemon_pid = pid;
 		}
 	    }
-
 	  g_strfreev (lines);
         }
       else
