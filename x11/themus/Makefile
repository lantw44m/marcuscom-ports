# New ports collection makefile for:	themus
# Date created:		13 April 2003
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	themus
PORTVERSION=	0.1.5
CATEGORIES=	x11 x11-fm gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.1
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A theme view for Nautilus

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix nautilus2
GNOME_DESKTOP_VERSION=2
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
	       	LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|' \
		${WRKSRC}/libtheme/gnome-theme-info.c

.include <bsd.port.mk>
