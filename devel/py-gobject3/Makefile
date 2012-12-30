# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	gobject
PORTVERSION=	3.2.2
CATEGORIES=	devel python
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/pygobject/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygobject-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for GObject

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo
RUN_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo

LATEST_LINK=	${PYTHON_PKGNAMEPREFIX}${PORTNAME}3
USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20
USE_PYTHON=	2.5+
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

# this port doesn't work with py-gobject < 2.28.6_2, clungle below
CONFLICTS=	py*-gtk-0* py*-gobject-2.*.[0-6] py*-gobject-2.*.[7-9] \
		py*-gobject-2.*.6_1
PLIST_SUB=	PYTHON_VER="${PYTHON_VER}"

OPTIONS_DEFINE=	LIBFFI
LIBFFI_DESC=	Enable libffi support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBFFI}
LIB_DEPENDS+=	ffi:${PORTSDIR}/devel/libffi
CONFIGURE_ARGS+=--with-ffi
.else
CONFIGURE_ARGS+=--without-ffi
.endif

.include <bsd.port.mk>
