# New ports collection makefile for:	gnome-backgrounds
# Date Created:				12 January 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-themes/gnome-backgrounds/Makefile,v 1.56 2011/10/04 17:55:39 kwm Exp $
#

PORTNAME=	gnome-backgrounds
PORTVERSION=	3.4.2
CATEGORIES=	x11-themes graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of backgrounds for GNOME

USE_XZ=		yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
