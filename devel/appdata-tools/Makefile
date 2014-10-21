# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	appdata-tools
PORTVERSION=	0.1.7
CATEGORIES=	devel
DIST_SUBDIR=	gnome3

WRKSRC=		${WRKDIR}/hughsie-appdata-tools-${GH_COMMIT}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	AppData is a subset of AppStream

LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup

GH_ACCOUNT=	hughsie
GH_PROJECT=	appdata-tools
GH_COMMIT=      b364e3e
GH_TAGNAME=	${GH_COMMIT}

GNU_CONFIGURE=	yes
#CONFIGURE_ARGS=	--enable-introspection=yes
USE_GITHUB=	yes
USES=		autoreconf gmake libtool pathfix pkgconfig
USE_GNOME=	gdkpixbuf2 glib20 gnomehier intlhack introspection:build
USE_LDCONFIG=	yes

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
