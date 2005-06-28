# New ports collection makefile for:	py-cairo
# Date created:		2004-12-05
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#	$MCom$
#

PORTNAME=	cairo
PORTVERSION=	0.5.1
CATEGORIES=	graphics python
MASTER_SITES=	http://cairographics.org/snapshots/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Python bindings for Cairo

BUILD_DEPENDS=	${PYNUMERIC}
LIB_DEPENDS=	cairo.1:${PORTSDIR}/graphics/cairo
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_REINPLACE=	yes
WANT_GNOME=	yes
USE_LIBTOOL_VER=15

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PYGTK)
USE_GNOME=	pygtk2
PLIST_SUB+=	GTK=""
.else
PLIST_SUB+=	GTK="@comment "
.endif

.if !defined(WITHOUT_SVG)
LIB_DEPENDS+=	svg-cairo.1:${PORTSDIR}/graphics/libsvg-cairo
PLIST_SUB+=	SVG=""
.else
PLIST_SUB+=	SVG="@comment "
.endif

pre-everything::
	@${ECHO_MSG} "Disable SVG support by defining WITHOUT_SVG"
	@${ECHO_MSG} "Disable PyGtk support by defining WITHOUT_PYGTK"
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
