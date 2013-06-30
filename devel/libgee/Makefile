# Created by: Frank Steinborn <steinex@nognu.de>
# $FreeBSD$
#    $MCom$

PORTNAME=	libgee
PORTVERSION=	0.8.6
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GObject collection library

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
USE_GMAKE=	yes
USE_XZ=		yes
USES=		pathfix pkgconfig
USE_GNOME=	glib20 gnomehier introspection:build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
