# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/gnome-terminal/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-terminal
PORTVERSION=	2.32.1
PORTREVISION=	3
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the GNOME 2 Desktop

LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification

CONFLICTS=	gnome-terminal-3.[0-9]*

USES=		gettext gmake pathfix pkgconfig
USE_BZIP2=	yes
INSTALLS_OMF=	yes
USE_XORG=	sm
USE_GNOME=	gnomeprefix intlhack gconf2 vte gnomedocutils libgnome
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gnome-terminal.schemas

post-patch:
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in \
		${WRKSRC}/configure ${WRKSRC}/config.h.in

.include <bsd.port.mk>
