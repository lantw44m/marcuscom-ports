# New ports collection makefile for:	libgnomekbd
# Date created:		2006-11-07
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/libgnomekbd3/Makefile,v 1.8 2011/04/10 15:14:12 mezz Exp $
#

PORTNAME=	libgnomekbd
PORTVERSION=	3.2.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME keyboard shared library

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	xklavier.12:${PORTSDIR}/x11/libxklavier

LATEST_LINK=	libgnomekbd3

CONFLICTS=	libgnomekbd-2.[0-9]*

USE_XZ=		yes
USE_GNOME=	gnomeprefix gnomehack ltverhack intltool gtk30
USE_AUTOTOOLS=	libtool
USE_XORG=	ice
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.libgnomekbd.desktop.gschema.xml \
		org.gnome.libgnomekbd.gschema.xml \
		org.gnome.libgnomekbd.keyboard.gschema.xml

.include <bsd.port.mk>
