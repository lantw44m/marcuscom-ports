# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/telepathy-logger/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	telepathy-logger
PORTVERSION=	0.4.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Logger utility library for the Telepathy framework

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib

LICENSE=	LGPL21

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20 intltool gnomedocutils ltverhack libxml2 libxslt:build \
		introspection:build
USE_SQLITE=	yes
USE_PYTHON_BUILD=	yes
GLIB_SCHEMAS=	org.freedesktop.Telepathy.Logger.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|/usr/bin/env python|g' \
		${WRKSRC}/tools/*.py

.include <bsd.port.mk>
