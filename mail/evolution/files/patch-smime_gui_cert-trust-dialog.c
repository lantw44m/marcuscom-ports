--- smime/gui/cert-trust-dialog.c.orig	Sat Jun  5 15:59:24 2004
+++ smime/gui/cert-trust-dialog.c	Sat Jun  5 16:00:01 2004
@@ -79,11 +79,13 @@
 		CERT_ChangeCertTrust (CERT_GetDefaultCertDB(), icert, &trust);
 		break;
 	case GTK_RESPONSE_ACCEPT: {
+		GtkWidget *dialog;
+		CERTCertificate *icert;
 		g_signal_stop_emission_by_name(w, "response");
 
 		/* just *what on earth* was chris thinking here!?!?!  copied from certificate-manager.c */
-		GtkWidget *dialog = ca_trust_dialog_show (data->cacert, FALSE);
-		CERTCertificate *icert = e_cert_get_internal_cert (data->cacert);
+		dialog = ca_trust_dialog_show (data->cacert, FALSE);
+		icert = e_cert_get_internal_cert (data->cacert);
 
 		ca_trust_dialog_set_trust (dialog,
 					   e_cert_trust_has_trusted_ca (icert->trust, TRUE,  FALSE, FALSE),
