# New ports collection makefile for:	gnome-themes
# Date Created:				05 October 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-themes/gnome-themes-standard/Makefile,v 1.18 2011/10/04 17:37:34 kwm Exp $
#

PORTNAME=	gnome-themes-standard
PORTVERSION=	3.2.1
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Standard themes for GNOME

CONFLICTS=	gnome-themes-2.[0-9]*

USE_XZ=		yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack gtk30 librsvg2
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
