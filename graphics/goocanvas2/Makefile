# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/graphics/goocanvas2/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	goocanvas
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Canvas widget for GTK+ 3

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

LATEST_LINK=	goocanvas2
USES=		pathfix
USE_GNOME=	gtk30 ltverhack
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_XZ=		yes

.include <bsd.port.mk>
