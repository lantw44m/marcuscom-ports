# New ports collection makefile for:	goocanvasmm
# Date created:		2008-08-10
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/goocanvasmm2/Makefile,v 1.4 2011/06/15 09:22:16 kwm Exp $

PORTNAME=	goocanvasmm
PORTVERSION=	1.90.6
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	C++ bindings for the goocanvas widget for GTK

LIB_DEPENDS=	gtkmm-3.0.1:${PORTSDIR}/x11-toolkits/gtkmm30 \
		goocanvas-2.0.9:${PORTSDIR}/graphics/goocanvas2

USE_GNOME=	gnomehack ltverhack
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation
USE_XZ=		yes
USE_GMAKE=	yes

.include <bsd.port.mk>
