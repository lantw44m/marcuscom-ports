# New ports collection makefile for:	telepathy-gabble
# Date created:				Apr 19 2007
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net-im/telepathy-gabble/Makefile,v 1.17 2011/07/07 07:07:13 kwm Exp $

PORTNAME=	telepathy-gabble
PORTVERSION=	0.14.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Jabber Connection Manager for Telepathy Framework

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		telepathy-glib>=0.14.5:${PORTSDIR}/net-im/telepathy-glib \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
LIB_DEPENDS=	soup-2.4.1:${PORTSDIR}/devel/libsoup \
		nice.10:${PORTSDIR}/net-im/libnice \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid \
		loudmouth-1.0:${PORTSDIR}/net-im/loudmouth \
		sqlite3.8:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

GNU_CONFIGURE=	yes
LDFLAGS=	${PTHREAD_LIBS}
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig glib20
USE_OPENSSL=	yes
USE_PYTHON_BUILD=	yes
CONFIGURE_ARGS=	--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt

MAN8=		telepathy-gabble.8

.if defined(WITH_OPENSSL_BASE)
CONFIGURE_ENV+=	OPENSSL_LIBS="-L/usr/lib -ssl -crypto" OPENSSL_CFLAGS="-I/usr/include"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
		${WRKSRC}/lib/ext/wocky/configure

.include <bsd.port.mk>
