# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	telepathy-haze
PORTVERSION=	0.6.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-haze/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libpurple connection manager for telepathy

LIB_DEPENDS=	purple:${PORTSDIR}/net-im/libpurple \
		idn:${PORTSDIR}/dns/libidn \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib

USES=		pathfix
USE_GNOME=	libxslt:build
CPPFLAGS+=	-I${LOCALBASE}/include
WRKSRC=		${WRKDIR}/telepathy-${PORTNAME}-${DISTVERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN8=		telepathy-haze.8

.include <bsd.port.mk>
