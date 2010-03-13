#!/bin/sh

plugin_srcs="addressbook-file/addressbook-file.c attachment-reminder/attachment-reminder.c audio-inline/audio-inline.c backup-restore/backup-restore.c bbdb/bbdb.c bogo-junk-plugin/bf-junk-filter.c caldav/caldav-source.c calendar-file/calendar-file.c calendar-http/calendar-http.c calendar-weather/calendar-weather.c contacts-map/contacts-map.c default-mailer/default-mailer.c default-source/default-source.c email-custom-header/email-custom-header.c external-editor/external-editor.c face/face.c google-account-setup/google-source.c groupwise-features/install-shared.c hula-account-setup/hula-account-setup.c image-inline/image-inline.c imap-features/imap-headers.c itip-formatter/itip-formatter.c mail-notification/mail-notification.c mail-to-task/mail-to-task.c mailing-list-actions/mailing-list-actions.c mark-all-read/mark-all-read.c plugin-manager/plugin-manager.c prefer-plain/prefer-plain.c profiler/profiler.c pst-import/pst-importer.c publish-calendar/publish-calendar.c sa-junk-plugin/em-junk-filter.c save-calendar/save-calendar.c startup-wizard/startup-wizard.c subject-thread/subject-thread.c templates/templates.c tnef-attachments/tnef-plugin.c vcard-inline/vcard-inline.c webdav-account-setup/webdav-contacts-source.c"

WRKSRC=$1

for i in ${plugin_srcs}; do
    if [ ! -f ${WRKSRC}/plugins/${i} ]; then
	echo "WARNING: Failed to find plugin source file ${WRKSRC}/plugins/${i}"
	continue
    fi
    cp ${WRKSRC}/plugins/${i} ${WRKSRC}/plugins/${i}.bak
    printf "const char * g_module_check_init (gpointer module);\n" >> ${WRKSRC}/plugins/${i}
    printf "const char *\ng_module_check_init (gpointer module) {\n\treturn NULL;\n}\n" >> ${WRKSRC}/plugins/${i}
    printf "void g_module_unload (gpointer module);\n" >> ${WRKSRC}/plugins/${i}
    printf "void\ng_module_unload (gpointer module) {\n\treturn;\n}\n" >> ${WRKSRC}/plugins/${i}
    dir=$(dirname ${WRKSRC}/plugins/${i})
    if ! grep -q e_plugin_lib_enable ${dir}/*.c; then
	printf "#include <e-util/e-config.h>\n" >> ${WRKSRC}/plugins/${i}
	printf "gint e_plugin_lib_enable (EPlugin *ep, gint enable);\n" >> ${WRKSRC}/plugins/${i}
	printf "gint\ne_plugin_lib_enable (EPlugin *ep, gint enable) {\n\treturn 0;\n}\n" >> ${WRKSRC}/plugins/${i}
    fi
done
