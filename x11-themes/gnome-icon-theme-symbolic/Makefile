# $FreeBSD$
#   $MCom$

PORTNAME=	gnome-icon-theme-symbolic
PORTVERSION=	3.4.0
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Symbolic Icons

BUILD_DEPENDS=	icon-naming-utils>=0.8.7:${PORTSDIR}/x11-themes/icon-naming-utils

USE_XZ=		yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USES=		pathfix
USE_PKGCONFIG=	build
USE_GNOME=	gnomeprefix
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
