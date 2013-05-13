# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/libwnck/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	libwnck
PORTVERSION=	2.30.7
PORTREVISION?=	0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library used for writing pagers and taskslists

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification

CONFLICTS=	libwnck-3.[0-9]*

USE_XORG=	xres x11
USE_GMAKE=	yes
USE_GNOME=	gtk20 ltverhack referencehack intlhack introspection
USES=		bison gettext pathfix
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>

.endif
