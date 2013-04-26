# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/libgnomekbd3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	libgnomekbd
PORTVERSION=	3.4.0.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME keyboard shared library

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	xklavier:${PORTSDIR}/x11/libxklavier

LATEST_LINK=	libgnomekbd3

CONFLICTS=	libgnomekbd-2.[0-9]*

USE_XZ=		yes
USE_GNOME=	gnomeprefix ltverhack intltool gtk30
USE_AUTOTOOLS=	libtool
USE_XORG=	ice
INSTALLS_ICONS=	yes
USES=		gettext pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.libgnomekbd.desktop.gschema.xml \
		org.gnome.libgnomekbd.gschema.xml \
		org.gnome.libgnomekbd.keyboard.gschema.xml

.include <bsd.port.mk>
