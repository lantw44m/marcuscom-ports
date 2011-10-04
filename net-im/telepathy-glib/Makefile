# New ports collection makefile for:	telepathy-glib
# Date created:				Apr 19 2007
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net-im/telepathy-glib/Makefile,v 1.31 2011/09/15 19:13:36 kwm Exp $

PORTNAME=	telepathy-glib
PORTVERSION=	0.15.7
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib utility library for the Telepathy framework

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		vala-vapigen>=0.13.4:${PORTSDIR}/lang/vala-vapigen \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS+=	vapigen:${PORTSDIR}/lang/vala-vapigen

USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig glib20 ltverhack
USE_PYTHON_BUILD=	yes
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ARGS=	--enable-vala-bindings

post-patch:
	@${REINPLACE_CMD} -e 's|\(^pkgconfigdir =\).*|\1 ${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/telepathy-glib/Makefile.in

.include <bsd.port.mk>
