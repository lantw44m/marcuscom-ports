# New ports collection makefile for:	freedesktop-sound-theme
# Date created:				15 August 2008
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	freedesktop-sound-theme
PORTVERSION=	1.0
CATEGORIES=	audio gnome
MASTER_SITES=	http://0pointer.de/public/
DISTNAME=	sound-theme-freedesktop

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sound theme based on the FreeDesktop specification

NO_BUILD=	yes
USE_GNOME=	gnomehier
WRKSRC=		${WRKDIR}/freedesktop

do-install:
	${MKDIR} ${PREFIX}/share/sounds/freedesktop/stereo
	${INSTALL_DATA} ${WRKSRC}/index.theme \
	    	${PREFIX}/share/sounds/freedesktop
	for f in ${WRKSRC}/stereo/*; do \
	    bn=$$(${BASENAME} $${f}) ; \
	    ${INSTALL_DATA} $${f} \
	    	${PREFIX}/share/sounds/freedesktop/stereo/$${bn} ; \
	done

.include <bsd.port.mk>
