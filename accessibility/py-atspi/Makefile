# New ports collection makefile for:   at-spi
# Date Created:			12 April 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/py-atspi/Makefile,v 1.27 2011/10/19 09:41:50 kwm Exp $
#

PORTNAME=	atspi
PORTVERSION=	2.4.0
CATEGORIES=	accessibility x11-toolkits python
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/pyatspi/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyatspi-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python API for the D-BUS based SPI framework

RUN_DEPENDS=	${LOCALBASE}/libexec/at-spi2-registryd:${PORTSDIR}/accessibility/at-spi2-core

CONFLICTS=	at-spi-1.[0-9]*

USE_XZ=		yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomehier intlhack pygobject3
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
