# New ports collection makefile for:    libgnomemm
# Date created:         22 May 2003
# Whom:                 Alexander Nedotsukov <bland@mail.ru>
#
# $FreeBSD: ports/x11/libgnomemm/Makefile,v 1.6 2003/10/18 05:19:45 bland Exp $
#

PORTNAME=	libgnomemm
PORTVERSION=	2.5.0
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.5
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libgnome library

LIB_DEPENDS=	gtkmm-2.3.2:${PORTSDIR}/x11-toolkits/gtk--2
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack lthack libgnome
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static

PLIST_SUB=	VERSION="2.5" API_VERSION="2.6"

.include <bsd.port.mk>
