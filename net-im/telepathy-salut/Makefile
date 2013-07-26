# Created by: Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net-im/telepathy-salut/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	telepathy-salut
PORTVERSION=	0.8.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Link-local Connection Manager for Telepathy Framework

LIB_DEPENDS=	avahi-glib:${PORTSDIR}/net/avahi-app \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib \
		soup-2.4:${PORTSDIR}/devel/libsoup

GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20 libxslt:build
USE_OPENSSL=	yes
USE_PYTHON_BUILD=	yes
USE_SQLITE=	3
CONFIGURE_ARGS=	--disable-Werror --enable-avahi-tests=no
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

MAN8=		telepathy-salut.8

post-patch:
	@${REINPLACE_CMD} -e 's|make -C|${GMAKE} -C|g' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/tests/Makefile.in

.include <bsd.port.mk>
