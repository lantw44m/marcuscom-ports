--- make-iso.c.orig	Wed Feb 16 19:34:31 2005
+++ make-iso.c	Tue Mar  1 00:41:35 2005
@@ -501,6 +501,10 @@
 
 		if (status == G_IO_STATUS_NORMAL) {
 			g_free (line);
+		} else if (status == G_IO_STATUS_EOF) {
+			if (mkisofs_output->debug)
+				g_print ("make_iso stdout: EOF\n");
+			return FALSE;
 		}
 	} else if (condition & G_IO_HUP) {
 		if (mkisofs_output->debug)
@@ -583,6 +587,12 @@
 			}
 
 			g_free (line);
+		} else if (status == G_IO_STATUS_EOF) {
+			if (mkisofs_output->debug)
+				g_print ("make_iso stderr: EOF\n");
+			nautilus_burn_progress_set_fraction (1.0);
+			g_main_loop_quit (mkisofs_output->loop);
+			return FALSE;
 		}
 	} else if (condition & G_IO_HUP) {
 		/* only handle the HUP when we have read all available lines of output */
@@ -719,6 +729,7 @@
 	argv [i++] = "-r";
 	if (use_joliet) {
 		argv [i++] = "-J";
+		argv[i++] = "-joliet-long";
 	}
 	if (has_utf8_support) {
 		argv [i++] = "-input-charset";
@@ -806,6 +817,7 @@
 	argv [i++] = "-r";
 	if (use_joliet) {
 		argv [i++] = "-J";
+		argv[i++] = "-joliet-long";
 	}
 	if (has_utf8_support) {
 		argv [i++] = "-input-charset";
