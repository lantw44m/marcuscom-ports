--- src/gnome-mount-properties-view.c.orig	Mon Nov 13 21:14:43 2006
+++ src/gnome-mount-properties-view.c	Mon Nov 13 21:36:10 2006
@@ -59,6 +59,33 @@ struct _GnomeMountPropertiesViewClass {
 	GtkVBoxClass base_class;
 };
 
+#ifdef __FreeBSD__
+static struct opt {
+	int o_opt;
+	const char *o_name;
+} optnames[] = {
+	{ MNT_ASYNC,		"asynchronous" },
+	{ MNT_EXPORTED,		"NFS exported" },
+	{ MNT_LOCAL,		"local" },
+	{ MNT_NOATIME,		"noatime" },
+	{ MNT_NOEXEC,		"noexec" },
+	{ MNT_NOSUID,		"nosuid" },
+	{ MNT_NOSYMFOLLOW,	"nosymfollow" },
+	{ MNT_QUOTA,		"with quotas" },
+	{ MNT_RDONLY,		"read-only" },
+	{ MNT_SYNCHRONOUS,	"synchronous" },
+	{ MNT_UNION,		"union" },
+	{ MNT_NOCLUSTERR,	"noclusterr" },
+	{ MNT_NOCLUSTERW,	"noclusterw" },
+	{ MNT_SUIDDIR,		"suiddir" },
+	{ MNT_SOFTDEP,		"soft-updates" },
+	{ MNT_MULTILABEL,	"multilabel" },
+	{ MNT_ACLS,		"acls" },
+	{ MNT_GJOURNAL,		"gjournal" },
+	{ 0, NULL }
+};
+#endif
+
 G_DEFINE_TYPE (GnomeMountPropertiesView, gm_properties_view, GTK_TYPE_VBOX)
 
 static void
@@ -445,13 +472,29 @@ static gboolean
 mtab_next (gpointer handle, char **device_file, char **mount_options, char **mount_fstype)
 {
 #ifdef __FreeBSD__
-#error FIXME TODO XXX fix this up for FreeBSD. Thanks.
 	struct mtab_handle *mtab = handle;
 
-	if (mtab->iter < mtab->n_mounts)
-		return mtab->mounts[mtab->iter++].f_mntfromname;
-	else
-		return NULL;
+	if (mtab->iter < mtab->n_mounts) {
+		struct opt *o;
+		int flags;
+		GString *optstr;
+
+		optstr = g_string_new("");
+		flags = mtab->mounts[mtab->iter].f_flags & MNT_VISFLAGMASK;
+
+		for (o = optnames; flags && o->o_opt; o++) {
+			if (flags & o->o_opt) {
+				g_string_append_printf(optstr, ", %s", o->o_name);
+				flags &= ~o->o_opt;
+			}
+		}
+		*device_file = mtab->mounts[mtab->iter].f_mntfromname;
+		*mount_options = g_string_free(optstr, FALSE);
+		*mount_fstype = mtab->mounts[mtab->iter++].f_fstypename;
+		return TRUE;
+	} else {
+		return FALSE;
+	}
 #else
 	struct mntent *mnt;
 
