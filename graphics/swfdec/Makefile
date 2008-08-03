# ex:ts=8
# Ports collection makefile for:	swfdec
# Date created:			Apr 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	swfdec
PORTVERSION=	0.7.4
CATEGORIES=	graphics
MASTER_SITES=	http://swfdec.freedesktop.org/download/swfdec/0.7/

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	Flash Rendering Library

LIB_DEPENDS=	oil-0.3.0:${PORTSDIR}/devel/liboil \
		soup-2.4.1:${PORTSDIR}/devel/libsoup

USE_LDCONFIG=	yes
USE_GNOME=	gnomehack gtk20 ltverhack
USE_GSTREAMER=	core good mp3 ffmpeg
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--with-audio=none
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION:R}

.include <bsd.port.mk>
