# New ports collection makefile for:	gmpc-wikipedia
# Date created:		March 27 2008
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD: ports/audio/gmpc-wikipedia/Makefile,v 1.12 2010/04/03 10:44:01 roam Exp $
#

PORTNAME=	gmpc-wikipedia
PORTVERSION=	0.19.0
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/${PORTVERSION}/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Wikipedia info for gmpc

LIB_DEPENDS=	mpd:${PORTSDIR}/audio/libmpd \
		curl.6:${PORTSDIR}/ftp/curl \
		webkitgtk-1.0.13:${PORTSDIR}/www/webkit-gtk2
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPEND=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USE_XORG=	x11
USE_GNOME=	gnomehack intltool
USE_LDCONFIG=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
