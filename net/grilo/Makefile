# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom$

PORTNAME=	grilo
PORTVERSION=	0.2.11
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Grilo is a framework focused on making media discovery and browsing

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		liboauth.so:${PORTSDIR}/net/liboauth \
		libtotem-plparser.so:${PORTSDIR}/multimedia/totem-pl-parser

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20 intlhack introspection:build libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-vala -disable-debug
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

#  --enable-debug include debug symbols
CONFIGURE_ARGS+=--enable-tests #          build unit tests

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	UI

UI_DESC=	Enable testing UI
UI_CONFIGURE_ENABLE=test-ui
UI_USE=		GNOME=gtk30

.include <bsd.port.mk>
