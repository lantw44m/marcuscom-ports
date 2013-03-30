# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/pangox-compat/Makefile,v 1.1 2013/03/30 10:23:38 kwm Exp $

PORTNAME=	pangox-compat
PORTVERSION=	0.0.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Depricated pangoX support.

BUILD_DEPENDS=	pango>=1.34.0:${PORTSDIR}/x11-toolkits/pango

USE_XZ=		yes
USE_XORG=	x11 ice
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		pathfix
USE_GNOME=	glib20 pango
USE_PKGCONFIG=	build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
