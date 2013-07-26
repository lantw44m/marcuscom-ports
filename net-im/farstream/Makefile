# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net-im/farstream/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	farstream
PORTVERSION=	0.2.3
CATEGORIES=	net-im devel
MASTER_SITES=	http://freedesktop.org/software/farstream/releases/farstream/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of GStreamer modules and libraries for videoconferencing

LIB_DEPENDS=	nice:${PORTSDIR}/net-im/libnice
RUN_DEPENDS=	libnice-gst1>=0:${PORTSDIR}/net-im/libnice-gst1

CONFLICTS=	farsight2-[0-9]*

USE_LDCONFIG=	yes
USE_PYTHON=	yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	glib20 ltverhack
USE_GSTREAMER1=	good bad
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
