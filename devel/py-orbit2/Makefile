# New ports collection makefile for:	py-orbit2
# Date created:				04 March 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/devel/py-orbit2/Makefile,v 1.26 2005/11/15 06:49:01 ade Exp $

PORTNAME=	orbit
PORTVERSION=	2.13.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/pyorbit/2.13
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
USE_AUTOTOOLS=	libtool:15
ORBIT_CONFIG=	${LOCALBASE}/bin/orbit2-config

.include <bsd.port.mk>
