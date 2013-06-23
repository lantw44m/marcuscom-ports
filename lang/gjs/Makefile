# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	gjs
PORTVERSION=	1.34.0
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Javascript binding

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		mozjs185:${PORTSDIR}/lang/spidermonkey185

USE_XZ=		yes
USES=		gettext pathfix pkgconfig shebangfix
USE_GMAKE=	yes
USE_PYTHON_BUILD=yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	cairo glib20 gnomeprefix introspection:build \
		intlhack ltverhack
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SHEBANG_FILES=	scripts/make-tests

.include <bsd.port.mk>
