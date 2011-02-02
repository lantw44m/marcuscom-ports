From a9fb511ced4cfaffb7109e58a9db66e6279e309c Mon Sep 17 00:00:00 2001
From: Punit Jain <jpunit@novell.com>
Date: Tue, 01 Feb 2011 06:47:05 +0000
Subject: bug #641069 - tnef plugin vulnerabilities

Resolves directory traversal and buffer overflow vulnerabilities.
---
diff --git a/plugins/tnef-attachments/tnef-plugin.c b/plugins/tnef-attachments/tnef-plugin.c
index e25bff8..4148008 100644
--- plugins/tnef-attachments/tnef-plugin.c
+++ plugins/tnef-attachments/tnef-plugin.c
@@ -25,6 +25,7 @@
 
 /* We include gi18n-lib.h so that we have strings translated directly for this package */
 #include <glib/gi18n-lib.h>
+#include <glib/gprintf.h>
 #include <string.h>
 #include <stdio.h>
 
@@ -67,6 +68,19 @@ guchar getRruleCount (guchar a, guchar b);
 guchar getRruleMonthNum (guchar a, guchar b);
 gchar * getRruleDayname (guchar a);
 
+static gchar* 
+sanitize_filename (const gchar *filename)
+{
+	gchar * sanitized_name;
+	sanitized_name = g_path_get_basename (filename);
+	if (sanitized_name == NULL || !g_strcmp0 (sanitized_name, ".")) {
+		g_free (sanitized_name);
+		return NULL;
+	} else {
+		return g_strdelimit (sanitized_name, " ", '_');
+	}
+}
+
 void
 org_gnome_format_tnef (gpointer ep, EMFormatHookTarget *t)
 {
@@ -216,8 +230,9 @@ void processTnef (TNEFStruct *tnef, const gchar *tmpdir) {
     Attachment *p;
     gint RealAttachment;
     gint object;
-    gchar ifilename[256];
-    gint i, count;
+    gchar *ifilename = NULL;
+    gchar *absfilename, *file;
+    gint count;
     gint foundCal=0;
 
     FILE *fptr;
@@ -255,10 +270,13 @@ void processTnef (TNEFStruct *tnef, const gchar *tmpdir) {
                     != MAPI_UNDEFINED) {
                 variableLength buf;
                 if ((buf.data = (gchar *) DecompressRTF (filename, &buf.size)) != NULL) {
-                    sprintf(ifilename, "%s/%s.rtf", tmpdir, tnef->subject.data);
-                    for (i=0; i<strlen (ifilename); i++)
-                        if (ifilename[i] == ' ')
-                            ifilename[i] = '_';
+                    file = sanitize_filename (tnef->subject.data);
+		    if (!file)
+			    return;
+                    absfilename = g_strconcat (file, ".rtf", NULL);
+                    ifilename = g_build_filename (tmpdir, file, NULL);
+		    g_free (absfilename);
+		    g_free (file);
 
                     if ((fptr = fopen(ifilename, "wb"))==NULL) {
                         printf("ERROR: Error writing file to disk!");
@@ -347,13 +365,14 @@ void processTnef (TNEFStruct *tnef, const gchar *tmpdir) {
                 }
                 if (filename->size == 1) {
                     filename->size = 20;
-                    sprintf(tmpname, "file_%03i.dat", count);
+                    g_sprintf(tmpname, "file_%03i.dat", count);
                     filename->data = tmpname;
                 }
-                sprintf(ifilename, "%s/%s", tmpdir, filename->data);
-                for (i=0; i<strlen (ifilename); i++)
-                    if (ifilename[i] == ' ')
-                        ifilename[i] = '_';
+                absfilename = sanitize_filename (filename->data);
+		if (!absfilename)
+		    return;
+		ifilename = g_build_filename (tmpdir, absfilename, NULL);
+                g_free (absfilename);
 
 		if ((fptr = fopen(ifilename, "wb"))==NULL) {
 		    printf("ERROR: Error writing file to disk!");
@@ -375,33 +394,43 @@ void processTnef (TNEFStruct *tnef, const gchar *tmpdir) {
         } /* if size>0 */
         p=p->next;
     } /* while p!= null */
+    g_free (ifilename);
 }
 
 void saveVCard (TNEFStruct *tnef, const gchar *tmpdir) {
-    gchar ifilename[512];
+    gchar *ifilename;
+    gchar *absfilename, *file=NULL;
     FILE *fptr;
     variableLength *vl;
     variableLength *pobox, *street, *city, *state, *zip, *country;
     dtr thedate;
-    gint boolean, i;
+    gint boolean;
 
     if ((vl = MAPIFindProperty (&(tnef->MapiProperties), PROP_TAG (PT_STRING8, PR_DISPLAY_NAME))) == MAPI_UNDEFINED) {
         if ((vl=MAPIFindProperty (&(tnef->MapiProperties), PROP_TAG (PT_STRING8, PR_COMPANY_NAME))) == MAPI_UNDEFINED) {
             if (tnef->subject.size > 0) {
-                sprintf(ifilename, "%s/%s.vcard", tmpdir, tnef->subject.data);
-            } else {
-                sprintf(ifilename, "%s/unknown.vcard", tmpdir);
-            }
-        } else {
-            sprintf(ifilename, "%s/%s.vcard", tmpdir, vl->data);
+    	       file = sanitize_filename (tnef->subject.data);
+		if (!file)
+		    return;
+		absfilename = g_strconcat (file, ".vcard", NULL);
+            } else
+                absfilename = g_strdup ("unknown.vcard");       
+     } else {
+            file = sanitize_filename (vl->data);
+	    if (!file)
+		return;
+	    absfilename = g_strconcat (file, ".vcard", NULL);
         }
     } else {
-        sprintf(ifilename, "%s/%s.vcard", tmpdir, vl->data);
+        file = sanitize_filename (vl->data);
+	if (!file)
+	    return;
+	absfilename = g_strconcat (file, ".vcard", NULL);
     }
-    for (i=0; i<strlen (ifilename); i++)
-        if (ifilename[i] == ' ')
-            ifilename[i] = '_';
-    printf("%s\n", ifilename);
+
+    ifilename = g_build_filename (tmpdir, absfilename, NULL);
+    g_free (file);
+    g_free (absfilename);
 
     if ((fptr = fopen(ifilename, "wb"))==NULL) {
             printf("Error writing file to disk!");
@@ -657,6 +686,7 @@ void saveVCard (TNEFStruct *tnef, const gchar *tmpdir) {
         fprintf(fptr, "END:VCARD\n");
         fclose (fptr);
     }
+    g_free (ifilename);
 }
 
 guchar getRruleCount (guchar a, guchar b) {
@@ -842,7 +872,7 @@ void printRrule (FILE *fptr, gchar *recur_data, gint size, TNEFStruct *tnef)
 }
 
 void saveVCalendar (TNEFStruct *tnef, const gchar *tmpdir) {
-    gchar ifilename[256];
+    gchar *ifilename;
     variableLength *filename;
     gchar *charptr, *charptr2;
     FILE *fptr;
@@ -851,7 +881,7 @@ void saveVCalendar (TNEFStruct *tnef, const gchar *tmpdir) {
     DWORD dword_val;
     dtr thedate;
 
-    sprintf(ifilename, "%s/calendar.ics", tmpdir);
+    ifilename = g_build_filename (tmpdir, "calendar.vcf", NULL);
     printf("%s\n", ifilename);
 
     if ((fptr = fopen(ifilename, "wb"))==NULL) {
@@ -1088,13 +1118,15 @@ void saveVCalendar (TNEFStruct *tnef, const gchar *tmpdir) {
         fprintf(fptr, "END:VCALENDAR\n");
         fclose (fptr);
     }
+    g_free (ifilename);
 }
 
 void saveVTask (TNEFStruct *tnef, const gchar *tmpdir) {
     variableLength *vl;
     variableLength *filename;
-    gint index,i;
-    gchar ifilename[256];
+    gint index;
+    gchar *ifilename;
+    gchar *absfilename, *file; 
     gchar *charptr, *charptr2;
     dtr thedate;
     FILE *fptr;
@@ -1111,10 +1143,14 @@ void saveVTask (TNEFStruct *tnef, const gchar *tmpdir) {
     while (vl->data[index] == ' ')
             vl->data[index--] = 0;
 
-    sprintf(ifilename, "%s/%s.ics", tmpdir, vl->data);
-    for (i=0; i<strlen (ifilename); i++)
-        if (ifilename[i] == ' ')
-            ifilename[i] = '_';
+    file = sanitize_filename (vl->data);
+    if (!file)
+	return;
+    absfilename = g_strconcat (file, ".vcf", NULL);
+    ifilename = g_build_filename (tmpdir, absfilename, NULL);
+    g_free (file);
+    g_free (absfilename);
+
     printf("%s\n", ifilename);
 
     if ((fptr = fopen(ifilename, "wb"))==NULL) {
@@ -1210,7 +1246,7 @@ void saveVTask (TNEFStruct *tnef, const gchar *tmpdir) {
         fprintf(fptr, "END:VCALENDAR\n");
         fclose (fptr);
     }
-
+    g_free (ifilename);
 }
 
 void fprintProperty (TNEFStruct *tnef, FILE *fptr, DWORD proptype, DWORD propid, const gchar text[]) {
--
cgit v0.8.3.1
