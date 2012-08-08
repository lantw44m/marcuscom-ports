# New ports collection makefile for:	telepathy-logger
# Date created:				23 July 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net-im/telepathy-logger/Makefile,v 1.12 2012/06/12 22:59:55 mezz Exp $

PORTNAME=	telepathy-logger
PORTVERSION=	0.4.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Logger utility library for the Telepathy framework

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig glib20 intltool gnomedocutils ltverhack
USE_SQLITE=	build
USE_PYTHON_BUILD=	yes
GLIB_SCHEMAS=	org.freedesktop.Telepathy.Logger.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|/usr/bin/env python|g' \
		${WRKSRC}/tools/*.py

.include <bsd.port.mk>
