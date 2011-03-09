# New ports collection makefile for:	gnome-screensaver
# Date created:		09 June 2005
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-screensaver3/Makefile,v 1.4 2011/03/09 15:59:43 kwm Exp $
#

PORTNAME=	gnome-screensaver
PORTVERSION=	2.91.91
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME screen saver and locker

LIB_DEPENDS=	notify.4:${PORTSDIR}/devel/libnotify \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
#RUN_DEPENDS=	xscreensaver-gl-helper:${PORTSDIR}/x11/xscreensaver-gnome-hacks

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_XORG=	xtst xxf86vm
USE_GNOME=	gnomeprefix gnomehack intlhack gnomemenus libgnomekbd3 \
		gnomedesktop3
GNOME_DESKTOP_VERSION=3
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
# explicit disable locking, the new binary needs work. doesn't unlock.
CONFIGURE_ARGS=	--disable-locking

MAN1=		gnome-screensaver-command.1 gnome-screensaver.1

#PLIST=	${WRKDIR}/pkg-plist
SUB_FILES+=	gnome-screensaver.pam

#XSCREENSAVER_DIR=	${LOCALBASE}/share/xscreensaver/config
#SCREENSAVER_DIR=	share/applications/screensavers

XSCREENSAVER_EXCLUDE=	"(popsquares.xml)"

OPTIONS=	PAM "Pluggable Authentication Module support" on \
		KEYRING "Enable GnomeKeyring integration (needs PAM)" on

.include <bsd.port.pre.mk>

.if defined(WITH_PAM)
RUN_DEPENDS+=		pam_helper:${PORTSDIR}/security/pam_helper
CONFIGURE_ARGS+=	--with-pam-prefix=${PREFIX}/etc/pam.d
PLIST_SUB+=		PAM=""
.else
CONFIGURE_ARGS+=	--disable-pam
PLIST_SUB+=		PAM="@comment "
.endif

.if defined(WITH_KEYRING) && defined(WITH_PAM)
SUB_LIST+=		PAM_KEYRING=
RUN_DEPENDS+=		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring
.else
SUB_LIST+=		PAM_KEYRING=\#
.endif

pre-everything::
.if defined(WITHOUT_PAM) && defined(WITH_KEYRING)
	@${ECHO_MSG} "Keyring integration is disabled because it needs PAM."
.endif

post-patch:
.if defined(WITH_PAM)
	@${REINPLACE_CMD} -e 's|/etc/pam.d|${PREFIX}/etc/pam.d|g' \
		${WRKSRC}/src/gs-auth-pam.c
.endif

#pre-install:
#	@${CAT} ${.CURDIR}/pkg-plist > ${PLIST}
#	@cd ${XSCREENSAVER_DIR} && ${FIND} -s * -maxdepth 1 -type f -name "*.xml" | \
#		${GREP} -Ev ${XSCREENSAVER_EXCLUDE} | \
#		${SED} -e 's:^:${SCREENSAVER_DIR}/:' | \
#		${SED} -e 's:[.]xml$$:.desktop:' >> ${PLIST}
#	@${ECHO_CMD} @dirrm ${SCREENSAVER_DIR} >> ${PLIST}

post-install:
	${CHOWN} root ${PREFIX}/libexec/gnome-screensaver-dialog
	${CHMOD} +s ${PREFIX}/libexec/gnome-screensaver-dialog
#	${MKDIR} ${PREFIX}/${SCREENSAVER_DIR}
#	cd ${PREFIX}/${SCREENSAVER_DIR} && \
#		${FIND} -s ${XSCREENSAVER_DIR} -maxdepth 1 -type f -name "*.xml" | \
#			${GREP} -Ev ${XSCREENSAVER_EXCLUDE} | \
#			${XARGS} ${WRKSRC}/data/migrate-xscreensaver-config.sh
.if defined(WITH_PAM)
	${INSTALL_DATA} ${WRKDIR}/gnome-screensaver.pam ${PREFIX}/etc/pam.d/gnome-screensaver
.endif

.include <bsd.port.post.mk>
