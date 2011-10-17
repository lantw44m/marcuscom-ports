# New ports collection makefile for:	farsight2
# Date created:				27 February 2009
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net-im/farsight2/Makefile,v 1.6 2011/08/11 19:48:47 kwm Exp $

PORTNAME=	farsight2
PORTVERSION=	0.0.29
CATEGORIES=	net-im devel
MASTER_SITES=	http://farsight.freedesktop.org/releases/farsight2/ \
		LOCAL/kwm

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of GStreamer modules and libraries for videoconferencing

LIB_DEPENDS=	nice.10:${PORTSDIR}/net-im/libnice

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack pkgconfig glib20 ltverhack
USE_GSTREAMER=	core good bad python
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
