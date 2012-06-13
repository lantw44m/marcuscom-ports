# New ports collection makefile for:	telepathy-farsight
# Date created:				27 February 2009
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom
#

PORTNAME=	telepathy-farstream
PORTVERSION=	0.4.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Farstream Connection Manager for Telepathy Framework

LIB_PC_DEPENDS=	gobject-2.0.pc:${PORTSDIR}/devel/glib20 \
		dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib \
		telepathy-glib.pc:${PORTSDIR}/net-im/telepathy-glib \
		farstream-0.1.pc:${PORTSDIR}/net-im/farstream

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

BUILD_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}
RUN_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack pkgconfig glib20 ltverhack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.mk>
