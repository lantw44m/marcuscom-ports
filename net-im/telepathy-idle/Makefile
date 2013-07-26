# Created by: Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/telepathy-idle/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	telepathy-idle
PORTVERSION=	0.1.11
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	IRC Connection Manager for Telepathy Framework

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20 libxslt:build

MAN8=		telepathy-idle.8

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL_BASE)
CONFIGURE_ENV+=	OPENSSL_LIBS="-L/usr/lib -lssl -lcrypto" OPENSSL_CFLAGS="-I/usr/include"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|strnlen(\([^,]*\), [^)]*)|strlen(\1)|' \
		${WRKSRC}/src/idle-connection.c \
		${WRKSRC}/src/idle-parser.c

.include <bsd.port.post.mk>
