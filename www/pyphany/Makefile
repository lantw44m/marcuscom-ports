# New ports collection makefile for:	pyphany
# Date created:				28 January 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyphany
PORTVERSION=	0.1
CATEGORIES=	www python gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.1
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of Python bindings for Epiphany

BUILD_DEPENDS=	epiphany:${PORTSDIR}/www/epiphany \
		${PYTHON_SITELIBDIR}/gtk-2.0/gnome/_gnome.so:${PORTSDIR}/x11-toolkits/py-gnome2
RUN_DEPENDS=	epiphany:${PORTSDIR}/www/epiphany \
		${PYTHON_SITELIBDIR}/gtk-2.0/gnome/_gnome.so:${PORTSDIR}/x11-toolkits/py-gnome2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack gnometarget intlhack
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION="1.5"

.include <bsd.port.mk>
