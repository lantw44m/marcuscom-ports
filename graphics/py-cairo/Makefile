# New ports collection makefile for:	py-cairo
# Date created:		2004-12-05
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#	$MCom: ports/graphics/py-cairo/Makefile,v 1.5 2005/07/04 05:46:33 ahze Exp $
#

PORTNAME=	cairo
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://cairographics.org/snapshots/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Python bindings for Cairo

BUILD_DEPENDS=	${PYNUMERIC}
LIB_DEPENDS=	cairo.1:${PORTSDIR}/graphics/cairo
RUN_DEPENDS=	${PYNUMERIC}

USE_PYTHON=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnometarget gnomehack
USE_AUTOTOOLS=	libtool:15

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SVG)
LIB_DEPENDS+=	svg-cairo.1:${PORTSDIR}/graphics/libsvg-cairo
PLIST_SUB+=	SVG=""
.else
PLIST_SUB+=	SVG="@comment "
.endif

pre-everything::
	@${ECHO_MSG} "Disable SVG support by defining WITHOUT_SVG"
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
