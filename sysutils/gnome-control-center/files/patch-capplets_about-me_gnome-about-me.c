--- capplets/about-me/gnome-about-me.c.orig	Tue Jul 25 23:14:52 2006
+++ capplets/about-me/gnome-about-me.c	Tue Jul 25 23:19:10 2006
@@ -419,7 +419,7 @@ about_me_load_photo (GnomeAboutMe *me, E
 
 	if (photo) {
 		me->have_image = TRUE;
-		e_image_chooser_set_image_data (E_IMAGE_CHOOSER (widget), photo->data, photo->length);
+		e_image_chooser_set_image_data (E_IMAGE_CHOOSER (widget), photo->data.inlined.data, photo->data.inlined.length);
 		e_contact_photo_free (photo);
 	} else {
 		me->have_image = FALSE;
@@ -490,15 +490,16 @@ about_me_update_photo (GnomeAboutMe *me)
 		}
 
 		photo = g_new0 (EContactPhoto, 1);
-		photo->data = data;
-		photo->length = length;
+		photo->data.inlined.data = data;
+		photo->data.inlined.length = length;
+		photo->data.inlined.mime_type = "image/png";
 		e_contact_set (me->contact, E_CONTACT_PHOTO, photo);
 
 		/* Save the image for GDM */
 		/* FIXME: I would have to read the default used by the gdmgreeter program */
 		file = g_strdup_printf ("%s/.face", g_get_home_dir ());
 		fp = fopen (file, "wb");
-		fwrite (photo->data, 1, photo->length, fp);
+		fwrite (photo->data.inlined.data, 1, photo->data.inlined.length, fp);
 		fclose (fp);
 
 		g_free (file);	
