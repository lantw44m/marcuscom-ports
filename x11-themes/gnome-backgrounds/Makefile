# New ports collection makefile for:	gnome-backgrounds
# Date Created:				12 January 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-themes/gnome-backgrounds/Makefile,v 1.15 2006/03/01 02:22:25 ahze Exp $
#

PORTNAME=	gnome-backgrounds
PORTVERSION=	2.13.92
CATEGORIES=	x11-themes graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of backgrounds for GNOME 2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnometarget gnomehack intlhack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
	       	LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
