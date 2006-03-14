# New ports collection makefile for:	libbonoboui
# Date created:				04 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-toolkits/libbonoboui/Makefile,v 1.41 2006/03/13 19:31:49 mezz Exp $
#

PORTNAME=	libbonoboui
PORTVERSION=	2.14.0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\.([0-9]+).*/\1.\2/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GUI frontend to the libbonobo component of GNOME 2

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier intlhack \
		libgnomecanvas libgnome
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.mk>
