--- addressbook/gui/component/addressbook-migrate.c	Mon Jan 26 23:55:13 2004
+++ /home/kaeru/cvs/gnome/evolution/addressbook/gui/component/addressbook-migrate.c	Fri Jan 30 03:07:34 2004
@@ -33,76 +33,88 @@
 #include <gtk/gtkprogressbar.h>
 #include <e-util/e-folder-map.h>
 
-static GtkWidget *window;
-static GtkLabel *label;
-static GtkProgressBar *progress;
+typedef struct {
+	/* this hash table maps old folder uris to new uids.  It's
+	   build in migrate_contact_folder and it's used in
+	   migrate_completion_folders. */
+	GHashTable *folder_uid_map;
+
+	ESourceList *source_list;
+
+	AddressbookComponent *component;
+
+	GtkWidget *window;
+	GtkLabel *label;
+	GtkProgressBar *progress;
+} MigrationContext;
 
 static void
-setup_progress_dialog (void)
+setup_progress_dialog (MigrationContext *context)
 {
 	GtkWidget *vbox, *hbox, *w;
-	
-	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
-	gtk_window_set_title ((GtkWindow *) window, _("Migrating..."));
-	gtk_window_set_modal ((GtkWindow *) window, TRUE);
-	gtk_container_set_border_width ((GtkContainer *) window, 6);
+
+	context->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
+	gtk_window_set_title (GTK_WINDOW (context->window), _("Migrating..."));
+	gtk_window_set_modal (GTK_WINDOW (context->window), TRUE);
+	gtk_container_set_border_width (GTK_CONTAINER (context->window), 6);
 	
 	vbox = gtk_vbox_new (FALSE, 6);
 	gtk_widget_show (vbox);
-	gtk_container_add ((GtkContainer *) window, vbox);
+	gtk_container_add (GTK_CONTAINER (context->window), vbox);
 	
 	w = gtk_label_new (_("The location and hierarchy of the Evolution contact "
 			     "folders has changed since Evolution 1.x.\n\nPlease be "
 			     "patient while Evolution migrates your folders..."));
-	gtk_label_set_line_wrap ((GtkLabel *) w, TRUE);
+	gtk_label_set_line_wrap (GTK_LABEL (w), TRUE);
 	gtk_widget_show (w);
-	gtk_box_pack_start_defaults ((GtkBox *) vbox, w);
+	gtk_box_pack_start_defaults (GTK_BOX (vbox), w);
 	
 	hbox = gtk_hbox_new (FALSE, 6);
 	gtk_widget_show (hbox);
-	gtk_box_pack_start_defaults ((GtkBox *) vbox, hbox);
+	gtk_box_pack_start_defaults (GTK_BOX (vbox), hbox);
 	
-	label = (GtkLabel *) gtk_label_new ("");
-	gtk_widget_show ((GtkWidget *) label);
-	gtk_box_pack_start_defaults ((GtkBox *) hbox, (GtkWidget *) label);
+	context->label = GTK_LABEL (gtk_label_new (""));
+	gtk_widget_show (GTK_WIDGET (context->label));
+	gtk_box_pack_start_defaults (GTK_BOX (hbox), GTK_WIDGET (context->label));
 	
-	progress = (GtkProgressBar *) gtk_progress_bar_new ();
-	gtk_widget_show ((GtkWidget *) progress);
-	gtk_box_pack_start_defaults ((GtkBox *) hbox, (GtkWidget *) progress);
+	context->progress = GTK_PROGRESS_BAR (gtk_progress_bar_new ());
+	gtk_widget_show (GTK_WIDGET (context->progress));
+	gtk_box_pack_start_defaults (GTK_BOX (hbox), GTK_WIDGET (context->progress));
 	
-	gtk_widget_show (window);
+	gtk_widget_show (context->window);
+
 }
 
 static void
-dialog_close (void)
+dialog_close (MigrationContext *context)
 {
-	gtk_widget_destroy ((GtkWidget *) window);
+	gtk_widget_destroy (context->window);
 }
 
 static void
-dialog_set_folder_name (const char *folder_name)
+dialog_set_folder_name (MigrationContext *context, const char *folder_name)
 {
 	char *text;
 	
 	text = g_strdup_printf (_("Migrating `%s':"), folder_name);
-	gtk_label_set_text (label, text);
+	gtk_label_set_text (context->label, text);
 	g_free (text);
 	
-	gtk_progress_bar_set_fraction (progress, 0.0);
+	gtk_progress_bar_set_fraction (context->progress, 0.0);
 	
 	while (gtk_events_pending ())
 		gtk_main_iteration ();
 }
 
 static void
-dialog_set_progress (double percent)
+dialog_set_progress (MigrationContext *context, double percent)
 {
 	char text[5];
 	
 	snprintf (text, sizeof (text), "%d%%", (int) (percent * 100.0f));
 	
-	gtk_progress_bar_set_fraction (progress, percent);
-	gtk_progress_bar_set_text (progress, text);
+	gtk_progress_bar_set_fraction (context->progress, percent);
+	gtk_progress_bar_set_text (context->progress, text);
 	
 	while (gtk_events_pending ())
 		gtk_main_iteration ();
@@ -170,7 +182,7 @@
 }
 
 static void
-migrate_contacts (EBook *old_book, EBook *new_book)
+migrate_contacts (MigrationContext *context, EBook *old_book, EBook *new_book)
 {
 	EBookQuery *query = e_book_query_any_field_contains ("");
 	GList *l, *contacts;
@@ -277,29 +289,25 @@
 
 		num_added ++;
 
-		dialog_set_progress ((double)num_added / num_contacts);
+		dialog_set_progress (context, (double)num_added / num_contacts);
 	}
 }
 
 static void
-migrate_contact_folder (char *old_path, ESourceGroup *dest_group, char *source_name)
+migrate_contact_folder_to_source (MigrationContext *context, char *old_path, ESource *new_source)
 {
 	char *old_uri = g_strdup_printf ("file://%s", old_path);
 	GError *e = NULL;
 
 	EBook *old_book = NULL, *new_book = NULL;
 	ESource *old_source;
-	ESource *new_source;
 	ESourceGroup *group;
 
 	group = e_source_group_new ("", old_uri);
 	old_source = e_source_new ("", "");
-	e_source_set_group (old_source, group);
-
-	new_source = e_source_new (source_name, source_name);
-	e_source_set_group (new_source, dest_group);
+	e_source_group_add_source (group, old_source, -1);
 
-	dialog_set_folder_name (source_name);
+	dialog_set_folder_name (context, e_source_peek_name (new_source));
 
 	old_book = e_book_new ();
 	if (!e_book_load_source (old_book, old_source, TRUE, &e)) {
@@ -313,12 +321,10 @@
 		goto finish;
 	}
 
-	migrate_contacts (old_book, new_book);
+	migrate_contacts (context, old_book, new_book);
 
  finish:
-	g_object_unref (new_source);
 	g_object_unref (old_source);
-	g_object_unref (dest_group);
 	g_object_unref (group);
 	if (old_book)
 		g_object_unref (old_book);
@@ -327,30 +333,46 @@
 	g_free (old_uri);
 }
 
+static void
+migrate_contact_folder (MigrationContext *context, char *old_path, ESourceGroup *dest_group, char *source_name)
+{
+	ESource *new_source;
+
+	new_source = e_source_new (source_name, source_name);
+	e_source_set_relative_uri (new_source, e_source_peek_uid (new_source));
+	e_source_group_add_source (dest_group, new_source, -1);
+
+	g_hash_table_insert (context->folder_uid_map, g_strdup (old_path), g_strdup (e_source_peek_uid (new_source)));
+
+	migrate_contact_folder_to_source (context, old_path, new_source);
+
+	g_object_unref (new_source);
+}
+
 #define LDAP_BASE_URI "ldap://"
-#define PERSONAL_RELATIVE_URI "Personal"
+#define PERSONAL_RELATIVE_URI "system"
 
 static void
-create_groups (AddressbookComponent *component,
-	       ESourceList   *source_list,
+create_groups (MigrationContext *context,
 	       ESourceGroup **on_this_computer,
-	       ESourceGroup **on_ldap_servers)
+	       ESourceGroup **on_ldap_servers,
+	       ESource      **personal_source)
 {
 	GSList *groups;
 	ESourceGroup *group;
-	ESource *personal_source = NULL;
-	char *base_uri, *base_uri_proto, *new_dir;
+	ESource *source = NULL;
+	char *base_uri, *base_uri_proto;
 
 	*on_this_computer = NULL;
 	*on_ldap_servers = NULL;
 
-	base_uri = g_build_filename (addressbook_component_peek_base_directory (component),
-				     "/addressbook/local/OnThisComputer/",
+	base_uri = g_build_filename (addressbook_component_peek_base_directory (context->component),
+				     "/addressbook/local/",
 				     NULL);
 
 	base_uri_proto = g_strconcat ("file://", base_uri, NULL);
 
-	groups = e_source_list_peek_groups (source_list);
+	groups = e_source_list_peek_groups (context->source_list);
 	if (groups) {
 		/* groups are already there, we need to search for things... */
 		GSList *g;
@@ -359,10 +381,10 @@
 
 			group = E_SOURCE_GROUP (g->data);
 
-			if (!strcmp (base_uri_proto, e_source_group_peek_base_uri (group)))
-				*on_this_computer = group;
-			else if (!strcmp (LDAP_BASE_URI, e_source_group_peek_base_uri (group)))
-				*on_ldap_servers = group;
+			if (!*on_this_computer && !strcmp (base_uri_proto, e_source_group_peek_base_uri (group)))
+				*on_this_computer = g_object_ref (group);
+			else if (!*on_ldap_servers && !strcmp (LDAP_BASE_URI, e_source_group_peek_base_uri (group)))
+				*on_ldap_servers = g_object_ref (group);
 		}
 	}
 
@@ -374,7 +396,7 @@
 		for (s = sources; s; s = s->next) {
 			ESource *source = E_SOURCE (s->data);
 			if (!strcmp (PERSONAL_RELATIVE_URI, e_source_peek_relative_uri (source))) {
-				personal_source = source;
+				*personal_source = g_object_ref (source);
 				break;
 			}
 		}
@@ -382,25 +404,23 @@
 	else {
 		/* create the local source group */
 		group = e_source_group_new (_("On This Computer"), base_uri_proto);
-		e_source_list_add_group (source_list, group, -1);
+		e_source_list_add_group (context->source_list, group, -1);
 
 		*on_this_computer = group;
 	}
 
-	if (!personal_source) {
+	if (!source) {
 		/* Create the default Person addressbook */
-		new_dir = g_build_filename (base_uri, "Personal/", NULL);
-		if (!e_mkdir_hier (new_dir, 0700)) {
-			personal_source = e_source_new (_("Personal"), PERSONAL_RELATIVE_URI);
-			e_source_group_add_source (*on_this_computer, personal_source, -1);
-		}
-		g_free (new_dir);
+		source = e_source_new (_("Personal"), PERSONAL_RELATIVE_URI);
+		e_source_group_add_source (*on_this_computer, source, -1);
+
+		*personal_source = source;
 	}
 
 	if (!*on_ldap_servers) {
 		/* Create the LDAP source group */
 		group = e_source_group_new (_("On LDAP Servers"), LDAP_BASE_URI);
-		e_source_list_add_group (source_list, group, -1);
+		e_source_list_add_group (context->source_list, group, -1);
 
 		*on_ldap_servers = group;
 	}
@@ -410,31 +430,33 @@
 }
 
 static gboolean
-migrate_local_folders (AddressbookComponent *component, ESourceGroup *on_this_computer)
+migrate_local_folders (MigrationContext *context, ESourceGroup *on_this_computer, ESource *personal_source)
 {
 	char *old_path = NULL;
-	char *local_contact_folder = NULL;
-	char *source_name = NULL;
 	GSList *dirs, *l;
+	char *local_contact_folder = NULL;
 
 	old_path = g_strdup_printf ("%s/evolution/local", g_get_home_dir ());
 
 	dirs = e_folder_map_local_folders (old_path, "contacts");
 
-	/* migrate the local addressbook first, to OnThisComputer/Personal */
+	/* migrate the local addressbook first, to local/system */
 	local_contact_folder = g_build_filename (g_get_home_dir (), "/evolution/local/Contacts",
 						 NULL);
-	source_name = _("Personal");
-	migrate_contact_folder (local_contact_folder, on_this_computer, source_name);
+	if (personal_source)
+		
 
 	for (l = dirs; l; l = l->next) {
-		/* skip the local contact folder, since we handle that
-		   specifically, mapping it to Personal */
-		if (!strcmp ((char*)l->data, local_contact_folder))
+		char *source_name;
+		/* we handle the system folder differently */
+		if (personal_source && !strcmp ((char*)l->data, local_contact_folder)) {
+			g_hash_table_insert (context->folder_uid_map, g_strdup (l->data), g_strdup (e_source_peek_uid (personal_source)));
+			migrate_contact_folder_to_source (context, local_contact_folder, personal_source);
 			continue;
+		}
 
 		source_name = get_source_name (on_this_computer, (char*)l->data);
-		migrate_contact_folder (l->data, on_this_computer, source_name);
+		migrate_contact_folder (context, l->data, on_this_computer, source_name);
 		g_free (source_name);
 	}
 
@@ -494,7 +516,7 @@
 }
 
 static gboolean
-migrate_ldap_servers (AddressbookComponent *component, ESourceGroup *on_ldap_servers)
+migrate_ldap_servers (MigrationContext *context, ESourceGroup *on_ldap_servers)
 {
 	char *sources_xml = g_strdup_printf ("%s/evolution/addressbook-sources.xml",
 					     g_get_home_dir ());
@@ -526,7 +548,7 @@
 		}
 		printf ("found %d contact servers to migrate\n", num_contactservers);
 
-		dialog_set_folder_name (_("LDAP Servers"));
+		dialog_set_folder_name (context, _("LDAP Servers"));
 
 		servernum = 0;
 		for (child = root->children; child; child = child->next) {
@@ -581,7 +603,7 @@
 				g_free (description);
 
 				servernum++;
-				dialog_set_progress ((double)servernum/num_contactservers);
+				dialog_set_progress (context, (double)servernum/num_contactservers);
 			}
 		}
 
@@ -630,9 +652,9 @@
 }
 
 static gboolean
-migrate_completion_folders (AddressbookComponent *component, ESourceList *source_list)
+migrate_completion_folders (MigrationContext *context)
 {
-	char *uris_xml = gconf_client_get_string (addressbook_component_peek_gconf_client (component),
+	char *uris_xml = gconf_client_get_string (addressbook_component_peek_gconf_client (context->component),
 						  "/apps/evolution/addressbook/completion/uris",
 						  NULL);
 
@@ -646,7 +668,7 @@
 		if (!doc)
 			return FALSE;
 
-		dialog_set_folder_name (_("Autocompletion Settings"));
+		dialog_set_folder_name (context, _("Autocompletion Settings"));
 
 		root = xmlDocGetRootElement (doc);
 		if (root == NULL || strcmp (root->name, "EvolutionFolderList") != 0) {
@@ -657,13 +679,13 @@
 		for (child = root->children; child; child = child->next) {
 			if (!strcmp (child->name, "folder")) {
 				char *physical_uri = e_xml_get_string_prop_by_name (child, "physical-uri");
-				char *uri;
-				ESource *source;
+				ESource *source = NULL;
 
-				/* if the physical uri is
-				   file://... we need to convert the
-				   path to the new directory
-				   structure.
+				/* if the physical uri is file://...
+				   we look it up in our folder_uid_map
+				   hashtable.  If it's a folder we
+				   converted over, we should get back
+				   a uid we can search for.
 
 				   if the physical_uri is anything
 				   else, we strip off the args
@@ -671,45 +693,25 @@
 				   for the uri. */
 
 				if (!strncmp (physical_uri, "file://", 7)) {
-					char *local_path = g_build_filename (g_get_home_dir (),
-									     "/evolution/local/",
-									     NULL);
-
-					if (!strncmp (physical_uri + 7, local_path, strlen (local_path))) {
-						char *path_extra;
-						char *path;
-
-						if (!strcmp (physical_uri + 7 + strlen (local_path), "Contacts"))
-							/* special case the ~/evolution/local/Contacts folder */
-							path_extra = "Personal";
-						else
-							path_extra = physical_uri + 7 + strlen (local_path);
-
-						path = g_build_filename (g_get_home_dir (),
-								 "/.evolution/addressbook/local/OnThisComputer",
-								 path_extra,
-								 NULL);
-						uri = g_strdup_printf ("file://%s", path);
-						g_free (path);
-					}
-					else {
-						/* if they somehow created a folder that lies
-						   outside the evolution folder tree, just pass
-						   the uri straight on */
-						uri = g_strdup (physical_uri);
-					}
+					char *uid = g_hash_table_lookup (context->folder_uid_map,
+									 physical_uri + 7);
 
-					g_free (local_path);
+					if (uid)
+						source = e_source_list_peek_source_by_uid (context->source_list, uid);
 				}
 				else {
+					char *uri;
 					char *semi = strchr (physical_uri, ';');
 					if (semi)
 						uri = g_strndup (physical_uri, semi - physical_uri);
 					else
 						uri = g_strdup (physical_uri);
+
+					source = get_source_by_uri (context->source_list, uri);
+
+					g_free (uri);
 				}
 
-				source = get_source_by_uri (source_list, uri);
 				if (source) {
 					e_source_set_property (source, "completion", "true");
 				}
@@ -719,7 +721,6 @@
 				}
 
 				g_free (physical_uri);
-				g_free (uri);
 			}
 		}
 
@@ -732,19 +733,47 @@
 	return TRUE;
 }
 
+static MigrationContext*
+migration_context_new (AddressbookComponent *component)
+{
+	MigrationContext *context = g_new (MigrationContext, 1);
+	
+	/* set up the mapping from old uris to new uids */
+	context->folder_uid_map = g_hash_table_new_full (g_str_hash, g_str_equal, (GDestroyNotify)g_free, (GDestroyNotify)g_free);
+
+	context->source_list = addressbook_component_peek_source_list (component);
+
+	/* initialize our dialog */
+	setup_progress_dialog (context);
+
+	context->component = component;
+
+	return context;
+}
+
+static void
+migration_context_free (MigrationContext *context)
+{
+	e_source_list_sync (context->source_list, NULL);
+
+	g_hash_table_destroy (context->folder_uid_map);
+	g_free (context);
+}
+
 int
 addressbook_migrate (AddressbookComponent *component, int major, int minor, int revision)
 {
-	ESourceList *source_list = addressbook_component_peek_source_list (component);
 	ESourceGroup *on_this_computer;
 	ESourceGroup *on_ldap_servers;
+	ESource *personal_source;
+	MigrationContext *context = migration_context_new (component);
 
 	printf ("addressbook_migrate (%d.%d.%d)\n", major, minor, revision);
 
 	/* we call this unconditionally now - create_groups either
 	   creates the groups/sources or it finds the necessary
 	   groups/sources. */
-	create_groups (component, source_list, &on_this_computer, &on_ldap_servers);
+	create_groups (context, &on_this_computer, &on_ldap_servers, &personal_source);
 
 	if (major <= 1) {
 		
@@ -756,19 +785,24 @@
 		    /* we're 0.x */
 		    (major == 0)) {
 
-			setup_progress_dialog ();
-			if (on_this_computer)
-				migrate_local_folders (component, on_this_computer);
-			if (on_ldap_servers)
-				migrate_ldap_servers (component, on_ldap_servers);
+			if (on_this_computer) {
+				migrate_local_folders (context, on_this_computer, personal_source);
+				g_object_unref (on_this_computer);
+			}
+			if (on_ldap_servers) {
+				migrate_ldap_servers (context, on_ldap_servers);
+				g_object_unref (on_ldap_servers);
+			}
+			if (personal_source)
+				g_object_unref (personal_source);
 
-			migrate_completion_folders (component, source_list);
+			migrate_completion_folders (context);
 
-			dialog_close ();
+			dialog_close (context);
 		}
 	}
 
-	e_source_list_sync (source_list, NULL);
+	migration_context_free (context);
 
 	return TRUE;
 }
