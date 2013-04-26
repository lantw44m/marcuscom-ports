# Created by: Frank Steinborn <steinex@nognu.de>
# $FreeBSD$
#    $MCom: ports/trunk/devel/libgee/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	libgee
PORTVERSION=	0.8.6
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GObject collection library

BUILD_DEPENDS=	gobject-introspection>=0.9.0:${PORTSDIR}/devel/gobject-introspection

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
USE_GMAKE=	yes
USE_XZ=		yes
USES=		pathfix pkgconfig
USE_GNOME=	glib20 gnomehier
USE_LDCONFIG=	yes

.include <bsd.port.mk>
