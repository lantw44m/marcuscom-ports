# New ports collection makefile for:	py-cairo
# Date created:		2004-12-05
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#	$MCom: ports/graphics/py-cairo/Makefile,v 1.10 2005/07/29 02:42:54 ahze Exp $
#

PORTNAME=	cairo
PORTVERSION=	0.6.0
CATEGORIES=	graphics python
MASTER_SITES=	http://cairographics.org/snapshots/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for Cairo

BUILD_DEPENDS=	${PYNUMERIC}
LIB_DEPENDS=	cairo.1:${PORTSDIR}/graphics/cairo
RUN_DEPENDS=	${PYNUMERIC}

USE_PYTHON=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gnomehack
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--without-pygtk

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SVG) && !exists(${LOCALBASE}/lib/libsvg-cairo.a)
PLIST_SUB+=	SVG="@comment "
.else
PLIST_SUB+=	SVG=""
LIB_DEPENDS+=	svg-cairo.1:${PORTSDIR}/graphics/libsvg-cairo
.endif

pre-everything::
	@${ECHO_MSG} "Disable SVG support by defining WITHOUT_SVG"
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|; \
		s|SUBDIRS = cairo examples test|SUBDIRS = cairo examples|' \
		${WRKSRC}/Makefile.in
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|-std=c99||' \
		${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
