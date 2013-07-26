# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/libwnck3/Makefile 18569 2013-06-18 07:58:41Z kwm $

PORTNAME=	libwnck
PORTVERSION=	3.4.5
PORTREVISION?=	0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library used for writing pagers and taskslists

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification

CONFLICTS=	libwnck-2.[0-9]*

LATEST_LINK=	libwnck3
USE_XORG=	xres x11
USE_GNOME=	gtk30 intlhack introspection ltverhack referencehack
USES=		bison gettext gmake pathfix
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>

.endif
