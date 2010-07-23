# New ports collection makefile for:	telepathy-logger
# Date created:				23 July 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTNAME=	telepathy-logger
PORTVERSION=	0.1.4
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Logger utility library for the Telepathy framework

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib \
		sqlite3.8:${PORTSDIR}/databases/sqlite3

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig glib20 ltverhack gconf2
USE_PYTHON_BUILD=	yes
#MAKE_JOBS_UNSAFE=	yes
GCONF_SCHEMAS=	telepathy-logger.schemas

#post-patch:
#	@${REINPLACE_CMD} -e 's|\(^pkgconfigdir =\).*|\1 ${PREFIX}/libdata/pkgconfig|' \
#		${WRKSRC}/telepathy-glib/Makefile.in

.include <bsd.port.mk>
