# New ports collection makefile for:	libgtksourceviewmm
# Date created:		2006-11-11
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$
#

PORTNAME=	gtksourceviewmm
PORTVERSION=	3.2.0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ binding of GtkSourceView3

LIB_DEPENDS=	gtkmm-3.0.1:${PORTSDIR}/x11-toolkits/gtkmm30

USE_LDCONFIG=	yes
USE_XZ=	yes
USE_GNOME=	gtksourceview3 gnomeprefix gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBAS}/lib
CONFIGURE_ARGS=	--disable-documentation

.include <bsd.port.mk>
