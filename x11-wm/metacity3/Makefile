# New ports collection makefile for:   metacity
# Date created:        21 May 2002
# Whom:                Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$
#   $MCom: ports/x11-wm/metacity3/Makefile,v 1.2 2011/06/21 18:06:06 kwm Exp $
#

PORTNAME=	metacity
PORTVERSION=	2.34.5
CATEGORIES=	x11-wm
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A window manager for the adult in you

BUILD_DEPENDS=	zenity:${PORTSDIR}/x11/zenity \
		gsettings-desktop-schemas>=3.3.0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification \
		gtop-2.0:${PORTSDIR}/devel/libgtop \
		canberra-gtk:${PORTSDIR}/audio/libcanberra
RUN_DEPENDS=	zenity:${PORTSDIR}/x11/zenity \
		gsettings-desktop-schemas>=3.3.0:${PORTSDIR}/devel/gsettings-desktop-schemas

CONFLICTS=	metacity-2.30.[0-9]*

LATEST_LINK=	metacity3
USE_XZ=		yes
USE_XORG=	x11 xcomposite xdamage xrender xcursor xinerama xext xrandr
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix intlhack gnomehack ltverhack gtk20
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GLIB_SCHEMAS=	org.gnome.metacity.gschema.xml

MAN1=		metacity-message.1 metacity-theme-viewer.1 \
		metacity-window-demo.1 metacity.1

.include <bsd.port.mk>
