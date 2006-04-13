# New ports collection makefile for:	py-orbit2
# Date created:				04 March 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/py-orbit2/Makefile,v 1.10 2006/03/13 19:31:40 mezz Exp $

PORTNAME=	orbit
PORTVERSION=	2.14.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/pyorbit/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyorbit-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for ORBit2

CONFLICTS=	py*-omniorb-[0-9]*

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack orbit2
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
ORBIT_CONFIG=	${LOCALBASE}/bin/orbit2-config

.include <bsd.port.mk>
