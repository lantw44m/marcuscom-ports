# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/clutter-gst/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	clutter-gst
PORTVERSION=	1.6.0
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter GStreamer integration

LIB_DEPENDS=	clutter-1.0:${PORTSDIR}/graphics/clutter

USE_GMAKE=	yes
USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USES=		pathfix
USE_GNOME=	ltverhack gnomeprefix
USE_GSTREAMER=	yes
USE_XORG=	xp x11
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
