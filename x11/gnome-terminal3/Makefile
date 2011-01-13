# New ports collection makefile for:	gnometerminal
# Date created:				1 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	gnome-terminal
PORTVERSION=	2.33.4
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the GNOME 3 Desktop

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification

USE_GETTEXT=	yes
USE_BZIP2=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_XORG=	sm
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2 vte3 gnomedocutils
GNU_CONFIGURE=	yes
GNOME_DESKTOP_VERSION=3
CONFIGURE_ARGS=	--with-gtk=3.0
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-terminal.schemas

post-patch:
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in \
		${WRKSRC}/configure ${WRKSRC}/config.h.in

.include <bsd.port.mk>
