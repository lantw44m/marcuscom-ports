# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net-im/telepathy-haze/Makefile 17271 2013-04-01 15:16:27Z kwm $

PORTNAME=	telepathy-haze
PORTVERSION=	0.6.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-haze/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libpurple connection manager for telepathy

LIB_DEPENDS=	purple:${PORTSDIR}/net-im/libpurple \
		idn:${PORTSDIR}/dns/libidn \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib

USES=		gmake pathfix
USE_GNOME=	libxslt:build
CPPFLAGS+=	-I${LOCALBASE}/include
WRKSRC=		${WRKDIR}/telepathy-${PORTNAME}-${DISTVERSION}
GNU_CONFIGURE=	yes

MAN8=		telepathy-haze.8

.include <bsd.port.mk>
