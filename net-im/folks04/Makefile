# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net-im/folks04/Makefile 18610 2013-06-30 16:33:05Z marcus $

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
USES=		pathfix gettext gmake
USE_GNOME=	intlhack gnomehier introspection:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION=22

.include <bsd.port.mk>
