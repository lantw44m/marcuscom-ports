# New ports collection makefile for:	gnomedesktop
# Date created:				13 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/x11/gnomedesktop/Makefile,v 1.36 2004/04/20 05:17:47 marcus Exp $
#

PORTNAME=	gnomedesktop
PORTVERSION=	2.7.92
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-desktop/2.7
DISTNAME=	gnome-desktop-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for GNOME 2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomehier libgnomeui
GNOME_DESKTOP_VERSION=2
USE_GMAKE=	yes
USE_BISON=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--with-gnome-distributor="FreeBSD GNOME Project" \
		--with-kde-datadir=${LOCALBASE}/share
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	gnome-about.1

.include <bsd.port.mk>
