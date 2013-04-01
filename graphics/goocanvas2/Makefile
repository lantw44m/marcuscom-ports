# New ports collection makefile for:	goocanvas
# Date created:		2006-09-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTNAME=	goocanvas
PORTVERSION=	2.0.1
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Canvas widget for GTK+ 3

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

LATEST_LINK=	goocanvas2
USE_GNOME=	gtk30 gnomehack ltverhack
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_XZ=		yes

.include <bsd.port.mk>
