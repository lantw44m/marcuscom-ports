# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/graphics/clutter-gtk3/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	clutter-gtk
PORTVERSION=	1.2.2
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+ Integration library for Clutter

LIB_DEPENDS=	clutter-1.0:${PORTSDIR}/graphics/clutter

LATEST_LINK=	clutter-gtk3
USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_GNOME=	gtk30 ltverhack gnomeprefix
USE_XORG=	xp x11
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
