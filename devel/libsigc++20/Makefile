# New ports collection makefile for:   libsigc++2
# Date created:        14 Feb 2004
# Whom:                Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libsigc++
PORTVERSION=	1.9.16
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libsigc
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Callback Framework for C++

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_GCC=	3.3
USE_GMAKE=	yes
LATEST_LINK=	libsigc++2
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack lthack gnometarget pkgconfig
USE_LIBTOOL_VER=13

.include <bsd.port.mk>
