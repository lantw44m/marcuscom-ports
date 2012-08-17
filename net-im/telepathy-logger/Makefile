# New ports collection makefile for:	telepathy-logger
# Date created:				23 July 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net-im/telepathy-logger/Makefile,v 1.13 2012/08/08 16:56:40 kwm Exp $

PORTNAME=	telepathy-logger
PORTVERSION=	0.4.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Logger utility library for the Telepathy framework

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack glib20 intltool gnomedocutils ltverhack libxml2 \
		libxslt:build
USE_PKGCONFIG=	build
USE_SQLITE=	yes
USE_PYTHON_BUILD=	yes
GLIB_SCHEMAS=	org.freedesktop.Telepathy.Logger.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|/usr/bin/env python|g' \
		${WRKSRC}/tools/*.py

.include <bsd.port.mk>
