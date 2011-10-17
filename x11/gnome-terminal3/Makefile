# New ports collection makefile for:	gnometerminal
# Date created:				1 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-terminal3/Makefile,v 1.10 2011/10/04 20:18:13 kwm Exp $
#

PORTNAME=	gnome-terminal
PORTVERSION=	3.2.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the GNOME 3 Desktop

CONFLICTS=	gnome-terminal-2.[0-9]*

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

LATEST_LINK=	gnome-terminal3
USE_GETTEXT=	yes
USE_XZ=		yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_XORG=	sm ice
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2 vte3 gnomedocutils
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=3.0
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gnome-terminal.schemas

post-patch:
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in \
		${WRKSRC}/configure ${WRKSRC}/config.h.in

.include <bsd.port.mk>
