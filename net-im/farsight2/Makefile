# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/farsight2/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	farsight2
PORTVERSION=	0.0.31
CATEGORIES=	net-im devel
MASTER_SITES=	http://farsight.freedesktop.org/releases/farsight2/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of GStreamer modules and libraries for videoconferencing

LIB_DEPENDS=	nice:${PORTSDIR}/net-im/libnice
RUN_DEPENDS=	libnice-gst010>=0:${PORTSDIR}/net-im/libnice-gst010

CONFLICTS=	farstream-[0-9]*

FETCH_ARGS=	-Fpr
USES=		gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_GNOME=	glib20 ltverhack
USE_GSTREAMER=	core good bad python
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
