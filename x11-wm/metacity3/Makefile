# Created by: Garrett Rooney <rooneg@electricjellyfish.net>
# $FreeBSD$
#   $MCom: ports/trunk/x11-wm/metacity3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	metacity
PORTVERSION=	2.34.13
CATEGORIES=	x11-wm
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A window manager for the adult in you

BUILD_DEPENDS=	zenity>=3.0.0:${PORTSDIR}/x11/zenity3 \
		itstool:${PORTSDIR}/textproc/itstool \
		xmllint:${PORTSDIR}/textproc/libxml2 \
		gsettings-desktop-schemas>=3.3.0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification \
		gtop-2.0:${PORTSDIR}/devel/libgtop \
		canberra-gtk:${PORTSDIR}/audio/libcanberra
RUN_DEPENDS=	zenity>=3.0.0:${PORTSDIR}/x11/zenity3 \
		gsettings-desktop-schemas>=3.3.0:${PORTSDIR}/devel/gsettings-desktop-schemas

CONFLICTS=	metacity-2.30.[0-9]*

LATEST_LINK=	metacity3
USE_XZ=		yes
USE_XORG=	x11 xcomposite xdamage xrender xcursor xinerama xext xrandr
USES=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix intlhack ltverhack gtk20
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.metacity.gschema.xml

MAN1=		metacity-message.1 metacity-theme-viewer.1 \
		metacity-window-demo.1 metacity.1

.include <bsd.port.mk>
