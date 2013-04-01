# Created by: Frank Steinborn <steinex@nognu.de>
# $FreeBSD$
#    $MCom$

PORTNAME=	libgee
PORTVERSION=	0.8.5
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GObject collection library

BUILD_DEPENDS=	gobject-introspection>=0.9.0:${PORTSDIR}/devel/gobject-introspection

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
USE_GMAKE=	yes
USE_XZ=		yes
USE_GNOME=	glib20 gnomehier gnomehack
USE_PKGCONFIG=	build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
