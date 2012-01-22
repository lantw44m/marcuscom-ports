# New ports collection makefile for:   gjs
# Date created:        14 Aug 2009
# Whom:                Pawel Worach <pawel.worach@gmail.com>
#
# $FreeBSD$
#   $MCom: ports/lang/gjs/Makefile,v 1.22 2011/12/15 15:27:48 kwm Exp $
#

PORTNAME=	gjs
PORTVERSION=	1.30.1
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Javascript binding

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_GECKO=	libxul
USE_XZ=		yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_PYTHON=	build
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gnomehack intlhack glib20 ltverhack
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/python|/usr/bin/env python|g' \
		${WRKSRC}/scripts/make-tests

.include <bsd.port.mk>
