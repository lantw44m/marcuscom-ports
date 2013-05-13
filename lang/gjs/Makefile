# Created by: Pawel Worach <pawel.worach@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/lang/gjs/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	gjs
PORTVERSION=	1.32.0
PORTREVISION=	1
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Javascript binding

BUILD_DEPENDS=	spidermonkey185>=1.8.5:${PORTSDIR}/lang/spidermonkey185
LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		mozjs185:${PORTSDIR}/lang/spidermonkey185

USE_XZ=		yes
USES=		gettext pathfix pkgconfig
USE_GMAKE=	yes
USE_PYTHON_BUILD=yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix intlhack glib20 ltverhack cairo introspection:build
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/python|/usr/bin/env python|g' \
		${WRKSRC}/scripts/make-tests

.include <bsd.port.mk>
