--- profiles/audio-profile.c.orig	Tue Feb 15 00:23:13 2005
+++ profiles/audio-profile.c	Tue Feb 15 00:23:31 2005
@@ -978,7 +978,6 @@
   }
   g_free (profile_id);
   profile_id = s;
-  g_free (s);
 
   profile_dir = gconf_concat_dir_and_key (CONF_PROFILES_PREFIX,
                                           profile_id);
