# New ports collection makefile for:	gnomespeech
# Date created:			11 May 2003
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/audio/gnomespeech/Makefile,v 1.2 2003/11/17 12:28:51 trevor Exp $
#

PORTNAME=	gnomespeech
PORTVERSION=	0.3.0
CATEGORIES=	audio gnome accessibility
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-speech/0.3
DISTNAME=	gnome-speech-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME text-to-speech API

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack libbonobo
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/festival)
WITH_FESTIVAL=	yes
.endif

.if defined(WITH_FESTIVAL)
RUN_DEPENDS=	festival:${PORTSDIR}/audio/festival
.endif

.include <bsd.port.post.mk>
