# New ports collection makefile for:	libgnomekbd
# Date created:		2006-11-07
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTNAME=	libgnomekbd
PORTVERSION=	2.17.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME keyboard shared library

LIB_DEPENDS=	xklavier.11:${PORTSDIR}/x11/libxklavier \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_BZIP2=	yes
USE_GNOME=	libgnomeui gnometarget gnomeprefix
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes

GCONF_SCHEMAS=	desktop_gnome_peripherals_keyboard_xkb.schemas
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

post-patch:
	@${MKDIR} ${WRKSRC}/m4
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
