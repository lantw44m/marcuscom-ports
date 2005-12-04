# New ports collection makefile for:	libbonoboui
# Date created:				04 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-toolkits/libbonoboui/Makefile,v 1.35 2005/11/16 00:18:05 ahze Exp $
#

PORTNAME=	libbonoboui
PORTVERSION=	2.13.0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.13
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GUI frontend to the libbonobo component of GNOME 2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier intlhack \
		libgnomecanvas libgnome
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.mk>
