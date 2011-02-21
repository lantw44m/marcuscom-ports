# New ports collection makefile for:	evolution
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/mail/evolution3/Makefile,v 1.5 2011/02/11 19:36:31 kwm Exp $
#

PORTNAME=	evolution
PORTVERSION=	2.91.90
CATEGORIES=	mail gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An integrated mail, calendar and address book distributed suite

LIB_DEPENDS=	nss3.1:${PORTSDIR}/security/nss \
		unique-3.0.0:${PORTSDIR}/x11-toolkits/libunique3 \
		notify.1:${PORTSDIR}/devel/libnotify
#		gtkimageview.0:${PORTSDIR}/x11-toolkits/gtkimageview
#RUN_DEPENDS=	${LOCALBASE}/lib/gnome-spell/libgnome-spell-component-0.3.so:${PORTSDIR}/textproc/gnome-spell

LATEST_LINK=	evolution3
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_BISON=	build
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack evolutiondataserver3 gtkhtml4 \
		desktopfileutils gnomedocutils ltasneededhack gnomedesktop3
# gnomedesktop
USE_AUTOTOOLS=	libtool
USE_GSTREAMER=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/evolution/%%VERSION%%
CONFIGURE_ARGS=	--enable-nss=yes \
		--enable-mono=no \
		--disable-nm \
		--with-sub-version=" FreeBSD GNOME Team Port"
# gweather and gtkimageview needs to get a gtk3 release first.
CONFIGURE_ARGS+=--disable-weather --disable-image-inline
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	apps_evolution_addressbook.schemas \
		apps-evolution-attachment-reminder.schemas \
		apps_evolution_calendar.schemas \
		apps_evolution_email_custom_header.schemas \
		apps_evolution_eplugin_face.schemas \
		apps-evolution-mail-notification.schemas \
		apps-evolution-mail-prompts-checkdefault.schemas \
		apps_evolution_shell.schemas \
		apps-evolution-template-placeholders.schemas \
		bogo-junk-plugin.schemas \
		evolution-mail.schemas

EVO_VERSION=	2.92
PLIST_SUB=	VERSION=${EVO_VERSION} \
		PORTVERSION=2.12

OPTIONS=	LDAP "Enable LDAP support" on \
		CANBERRA "Enable canberra plugin" on \
		SPAMASSASSIN "Enable SpamAssassin spam filtering" off
#		PST "Enable Outlook .pst importer" off \

.include <bsd.port.pre.mk>

USE_LDCONFIG=	${PREFIX}/lib/evolution/${EVO_VERSION}

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-openldap=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-openldap=no
.endif

.if defined(WITH_SPAMASSASSIN)
RUN_DEPENDS+=	spamassassin:${PORTSDIR}/mail/p5-Mail-SpamAssassin
.endif

.if defined(HEIMDAL_HOME) || defined(WITH_HEIMDAL) || defined(NO_KERBEROS)
HEIMDAL_HOME?=		${LOCALBASE}
LIB_DEPENDS+=		krb5:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=	--with-krb5=${HEIMDAL_HOME} \
			--with-krb5-includes=${HEIMDAL_HOME}/include
KRB5_LIB=		`${HEIMDAL_HOME}/bin/krb5-config gssapi --libs`
.elif !defined(NO_KERBEROS)
CONFIGURE_ARGS+=	--with-krb5=/usr
KRB5_LIB=		`/usr/bin/krb5-config gssapi --libs`
.endif

.if defined(WITH_CANBERRA)
LIB_DEPENDS+=	canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3
CONFIGURE_ARGS+=--enable-canberra=yes
PLIST_SUB+=	CANBERRA=""
.else
CONFIGURE_ARGS+=--enable-canberra=no
PLIST_SUB+=	CANBERRA="@comment "
.endif

# libpst doesn't install a .pc file, evo configure needs that
#.if defined(WITH_PST)
#CONFIGURE_ARGS+=	--enable-pst-import
#BUILD_DEPENDS+=		lspst:${PORTSDIR}/mail/libpst
#RUN_DEPENDS+=		lspst:${PORTSDIR}/mail/libpst
#PLIST_SUB+=		PST=""
#.else
CONFIGURE_ARGS+=	--disable-pst-import
PLIST_SUB+=		PST="@comment "
#.endif

post-patch:
	@${REINPLACE_CMD} -e '/^plugins_standard_always/s/audio-inline//' \
	    	-e 's|-lkrb5 -lcrypto -lasn1 -lcom_err -lroken -lgssapi|${KRB5_LIB}|g' \
		-e 's|-Wl,--no-undefined||g' \
		-e 's|-Wmissing-include-dirs||g' \
	    	${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g' \
		${WRKSRC}/plugins/bogo-junk-plugin/bf-junk-filter.c
	@${REINPLACE_CMD} -e 's|/usr/sbin|${LOCALBASE}/bin|g' \
		${WRKSRC}/plugins/sa-junk-plugin/em-junk-filter.c
	@${SH} ${FILESDIR}/fix-plugins.sh ${WRKSRC}

.include <bsd.port.post.mk>
