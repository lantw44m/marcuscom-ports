# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/www/libsocialweb/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	libsocialweb
PORTVERSION=	0.25.20
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	A personal social data server.

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	rest-0.7:${PORTSDIR}/www/rest \
		json-glib-1.0:${PORTSDIR}/devel/json-glib

USE_GNOME=	glib20 intlhack gconf2 introspection:build gnomehier
USE_XZ=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gettext pathfix
CONFIGURE_ARGS=	--enable-vala-bindings
# review if we want all the services enabled, because of not completely
# safe public API security wise?
CONFIGURE_ARGS+=--enable-all-services 

.include <bsd.port.mk>
