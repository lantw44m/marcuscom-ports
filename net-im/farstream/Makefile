# New ports collection makefile for:	farsight2
# Date created:				27 February 2009
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	farstream
PORTVERSION=	0.1.2
CATEGORIES=	net-im devel
MASTER_SITES=	http://freedesktop.org/software/farstream/releases/farstream/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of GStreamer modules and libraries for videoconferencing

LIB_DEPENDS=	nice.10:${PORTSDIR}/net-im/libnice

FETCH_ARGS=	-Fpr
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack pkgconfig glib20 ltverhack
USE_GSTREAMER=	core good bad python
USE_AUTOTOOLS=	libtool
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
