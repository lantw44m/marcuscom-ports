# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/libwnck3/Makefile,v 1.12 2012/05/25 10:55:08 kwm Exp $

PORTNAME=	libwnck
PORTVERSION=	3.4.2
PORTREVISION?=	0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library used for writing pagers and taskslists

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

CONFLICTS=	libwnck-2.[0-9]*

LATEST_LINK=	libwnck3
USE_GETTEXT=	yes
USE_XORG=	xres x11
USE_GMAKE=	yes
USE_GNOME=	gtk30 ltverhack referencehack intlhack
USES=		bison pathfix
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>

.endif
