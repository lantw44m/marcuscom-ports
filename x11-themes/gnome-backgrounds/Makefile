# New ports collection makefile for:	gnome-backgrounds
# Date Created:				12 January 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-themes/gnome-backgrounds/Makefile,v 1.35 2008/07/23 04:18:08 marcus Exp $
#

PORTNAME=	gnome-backgrounds
PORTVERSION=	2.23.90
CATEGORIES=	x11-themes graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of backgrounds for GNOME 2

USE_BZIP2=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnometarget gnomehack intlhack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
	       	LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
