# New ports collection makefile for:	clutter-gst
# Date created:		2008-12-25
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/multimedia/clutter-gst/Makefile,v 1.9 2011/06/06 18:26:03 kwm Exp $

PORTNAME=	clutter-gst
PORTVERSION=	1.3.14
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter GStreamer integration

LIB_DEPENDS=	clutter-glx-1.0:${PORTSDIR}/graphics/clutter

USE_GMAKE=	yes
USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack ltverhack gnomeprefix
USE_GSTREAMER=	yes
USE_XORG=	xp x11
USE_LDCONFIG=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
