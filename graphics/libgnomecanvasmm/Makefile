# New ports collection makefile for:    libgnomecanvasmm
# Date created:         22 May 2003
# Whom:                 Alexander Nedotsukov <bland@mail.ru>
#
# $FreeBSD: ports/graphics/libgnomecanvasmm/Makefile,v 1.4 2003/08/25 23:37:58 bland Exp $
#

PORTNAME=	libgnomecanvasmm
PORTVERSION=	2.5.0
PORTREVISION=	3
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.5
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libgnomecanvas library

LIB_DEPENDS=	gtkmm-2.3.4:${PORTSDIR}/x11-toolkits/gtk--2
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack libgnomecanvas lthack
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static

PLIST_SUB=	VERSION="2.5" API_VERSION="2.6"

.include <bsd.port.mk>
