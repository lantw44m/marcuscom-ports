# New ports collection makefile for:	py-gobject
# Date created:				10 January 2006
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/py-gobject/Makefile,v 1.32 2009/08/12 01:41:09 ahze Exp $
#

PORTNAME=	gobject
PORTVERSION=	2.19.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/pygobject/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygobject-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for GObject

LIB_DEPENDS=	girepository-1.0.0:${PORTSDIR}/devel/gobject-introspection

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-docs

CONFLICTS=	py*-gtk-0*
PLIST_SUB=	PYTHON_VER="${PYTHON_VER}"

.include <bsd.port.mk>
