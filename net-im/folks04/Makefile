# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	folks
PORTVERSION=	0.4.3
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	library to aggregates people from multiple sources

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	gee:${PORTSDIR}/devel/libgee06 \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib

CONFLICTS=	folks-0.[6-9].[0-9]*

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USES=		pathfix gettext
USE_GNOME=	intlhack gnomehier introspection:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION=22

.include <bsd.port.mk>
