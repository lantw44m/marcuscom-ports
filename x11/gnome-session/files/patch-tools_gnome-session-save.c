--- tools/gnome-session-save.c	2008/09/01 16:49:20	5029
+++ tools/gnome-session-save.c	2008/09/29 15:16:06	5128
@@ -45,7 +45,7 @@
 
 /* True if killing. This is deprecated, but we keep it for compatibility
  * reasons. */
-static gboolean kill = FALSE;
+static gboolean kill_session = FALSE;
 
 /* The real options that should be used now. They are not ambiguous. */
 static gboolean logout = FALSE;
@@ -67,7 +67,7 @@
         {"force-logout", '\0', 0, G_OPTION_ARG_NONE, &force_logout, N_("Log out, ignoring any existing inhibitors"), NULL},
         {"logout-dialog", '\0', 0, G_OPTION_ARG_NONE, &logout_dialog, N_("Show logout dialog"), NULL},
         {"shutdown-dialog", '\0', 0, G_OPTION_ARG_NONE, &shutdown_dialog, N_("Show shutdown dialog"), NULL},
-        {"kill", '\0', 0, G_OPTION_ARG_NONE, &kill, N_("Kill session"), NULL},
+        {"kill", '\0', 0, G_OPTION_ARG_NONE, &kill_session, N_("Kill session"), NULL},
         {"gui",  '\0', 0, G_OPTION_ARG_NONE, &show_error_dialogs, N_("Use dialog boxes for errors"), NULL},
         {"silent", '\0', 0, G_OPTION_ARG_NONE, &no_interaction, N_("Do not require confirmation"), NULL},
         {NULL}
@@ -259,7 +259,7 @@
         }
 
         conflicting_options = 0;
-        if (kill)
+        if (kill_session)
                 conflicting_options++;
         if (logout)
                 conflicting_options++;
@@ -272,7 +272,7 @@
         if (conflicting_options > 1)
                 display_error (_("Program called with conflicting options"));
 
-        if (kill) {
+        if (kill_session) {
                 if (no_interaction)
                         logout = TRUE;
                 else
