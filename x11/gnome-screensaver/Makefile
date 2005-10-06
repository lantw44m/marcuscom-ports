# New ports collection makefile for:	gnome-screensaver
# Date created:		09 June 2005
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-screensaver/Makefile,v 1.17 2005/09/23 23:16:22 marcus Exp $
#

PORTNAME=	gnome-screensaver
PORTVERSION=	0.0.15
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.0

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME screen saver and locker

LIB_DEPENDS=	dbus-1.1:${PORTSDIR}/devel/dbus
RUN_DEPENDS=	xscreensaver-gl-helper:${PORTSDIR}/x11/xscreensaver-gnome-hacks

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui gnomemenus
CONFIGURE_ARGS=	--disable-pam \
		--with-gdm-config=${X11BASE}/etc/gdm/gdm.conf \
		--with-xscreensaverdir=${X11BASE}/share/xscreensaver/config
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-screensaver.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/src/gs-job.c

post-install:
	${CHOWN} root ${PREFIX}/libexec/gnome-screensaver-dialog
	${CHMOD} +s ${PREFIX}/libexec/gnome-screensaver-dialog

.include <bsd.port.mk>
