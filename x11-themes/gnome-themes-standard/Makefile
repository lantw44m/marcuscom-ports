# New ports collection makefile for:	gnome-themes
# Date Created:				05 October 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-themes/gnome-themes-standard/Makefile,v 1.6 2011/03/09 22:45:02 kwm Exp $
#

PORTNAME=	gnome-themes-standard
PORTVERSION=	2.91.91.1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Standard themes for GNOME

USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack gtk30
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
