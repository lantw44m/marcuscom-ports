# New ports collection makefile for:    glibmm
# Date created:         		04 December 2003
# Whom:                 		Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glibmm
PORTVERSION=	2.3.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interfaces for glib2

LIB_DEPENDS=    sigc-1.2.5:${PORTSDIR}/devel/libsigc++12
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget glib20
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static

.include <bsd.port.mk>
