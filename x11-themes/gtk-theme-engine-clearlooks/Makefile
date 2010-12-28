# New ports collection makefile for:	gtk-theme-engine-clearlooks
# Date Created:				28 Dec 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	gtk-theme-engine-clearlooks
PORTVERSION=	2.91.5
CATEGORIES=	x11-themes
MASTER_SITES=	GNOME
#MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/3$//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
#DISTNAME=	${PORTNAME:S/3$//}-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clearlooks theme engine

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gtk30 intlhack 
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
