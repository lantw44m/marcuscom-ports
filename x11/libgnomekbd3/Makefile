# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11/libgnomekbd3/Makefile,v 1.10 2012/06/14 04:21:55 mezz Exp $

PORTNAME=	libgnomekbd
PORTVERSION=	3.6.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME keyboard shared library

BUILD_DEPENDS=	libxklavier>=5.2:${PORTSDIR}/x11/libxklavier
LIB_DEPENDS=	xklavier:${PORTSDIR}/x11/libxklavier

LATEST_LINK=	libgnomekbd3

CONFLICTS=	libgnomekbd-2.[0-9]*

USE_XZ=		yes
USE_GNOME=	gnomeprefix ltverhack intltool gtk30 introspection:build
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
