# New ports collection makefile for:   libsocialweb
# Date Created:			19 Feb 2011
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libsocialweb
PORTVERSION=	0.25.20
CATEGORIES=	www gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	A personal social data server.

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	rest-0.7.0:${PORTSDIR}/www/rest \
		json-glib-1.0.0:${PORTSDIR}/devel/json-glib

USE_GNOME=	gnomehack glib20 intlhack gconf2
USE_XZ=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--enable-all-services

.include <bsd.port.mk>
