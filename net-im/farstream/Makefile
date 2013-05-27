# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net-im/farstream/Makefile,v 1.2 2012/06/13 09:31:14 kwm Exp $

PORTNAME=	farstream
PORTVERSION=	0.2.3
CATEGORIES=	net-im devel
MASTER_SITES=	http://freedesktop.org/software/farstream/releases/farstream/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of GStreamer modules and libraries for videoconferencing

LIB_DEPENDS=	nice:${PORTSDIR}/net-im/libnice
RUN_DEPENDS=	libnice-gst1>=0:${PORTSDIR}/net-im/libnice-gst1

CONFLICTS=	farsight2-[0-9]*

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USES=		gettext pathfix pkgconfig
USE_GNOME=	glib20 ltverhack
USE_GSTREAMER1=	good bad
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
