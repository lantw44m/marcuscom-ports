# New ports collection makefile for:	telepathy-salut
# Date created:				Apr 16 2007
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net-im/telepathy-salut/Makefile,v 1.4 2009/01/08 07:12:15 marcus Exp $
#

PORTNAME=	telepathy-salut
PORTVERSION=	0.6.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Link-local Connection Manager for Telepathy Framework

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	avahi-glib.1:${PORTSDIR}/net/avahi-app \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib \
		soup-2.4.1:${PORTSDIR}/devel/libsoup

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig glib20
USE_OPENSSL=	yes
USE_PYTHON_BUILD=	yes
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-Werror
CPPFLAGS+=	${PTHREAD_CFLAGS}

MAN8=		telepathy-salut.8

post-patch:
	@${REINPLACE_CMD} -e 's|make -C|${GMAKE} -C|g' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/tests/Makefile.in

.include <bsd.port.mk>
