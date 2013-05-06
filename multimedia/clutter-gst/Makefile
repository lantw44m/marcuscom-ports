# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/multimedia/clutter-gst/Makefile,v 1.16 2012/06/26 08:02:35 kwm Exp $

PORTNAME=	clutter-gst
PORTVERSION=	2.0.2
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter GStreamer integration

LIB_DEPENDS=	clutter-1.0:${PORTSDIR}/graphics/clutter

USE_GMAKE=	yes
USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USES=		pathfix
USE_GNOME=	ltverhack gnomeprefix gnomehier
USE_GSTREAMER1=	yes
USE_XORG=	xp x11
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
