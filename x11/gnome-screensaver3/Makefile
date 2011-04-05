# New ports collection makefile for:	gnome-screensaver
# Date created:		09 June 2005
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-screensaver3/Makefile,v 1.11 2011/03/31 10:55:11 kwm Exp $
#

PORTNAME=	gnome-screensaver
PORTVERSION=	3.0.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME screen saver and locker

LIB_DEPENDS=	notify.4:${PORTSDIR}/devel/libnotify \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	pam_helper:${PORTSDIR}/security/pam_helper \
		${LOCALBASE}/lib/pam_gnome_keyring.so:${PORTSDIR}/security/gnome-keyring3

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
CONFIGURE_ARGS=	--with-pam-prefix=${PREFIX}/etc/pam.d

MAN1=		gnome-screensaver-command.1 gnome-screensaver.1

SUB_FILES+=	gnome-screensaver.pam

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/pam.d|${PREFIX}/etc/pam.d|g' \
		${WRKSRC}/src/gs-auth-pam.c
	@${REINPLACE_CMD} -e 's|gs-auth-pam.|gs-auth-helper.|g' \
		${WRKSRC}/src/Makefile.in
	@${ECHO} "#define PASSWD_HELPER_PROGRAM \"/usr/local/bin/pam_helper\"" \
		>> ${WRKSRC}/config.h.in

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
	${INSTALL_DATA} ${WRKDIR}/gnome-screensaver.pam \
		${PREFIX}/etc/pam.d/gnome-screensaver

.include <bsd.port.mk>
