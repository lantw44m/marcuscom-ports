# New ports collection makefile for:	goocanvasmm
# Date created:		2008-08-10
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/goocanvasmm/Makefile,v 1.2 2009/01/09 11:30:01 kwm Exp $

PORTNAME=	goocanvasmm2
PORTVERSION=	1.9.0
CATEGORIES=	graphics
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=     sources/${PORTNAME:S/2//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	${PORTNAME:S/2//}-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	C++ bindings for the goocanvas widget for GTK

LIB_DEPENDS=	gtkmm-3.0.1:${PORTSDIR}/x11-toolkits/gtkmm30 \
		goocanvas-2.0.8:${PORTSDIR}/graphics/goocanvas2

USE_GNOME=	gnomehack ltverhack
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-documentation

.include <bsd.port.mk>
