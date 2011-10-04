# New ports collection makefile for:	gucharmap
# Date created:				02 Mar 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/gucharmap3/Makefile,v 1.7 2011/09/19 18:47:34 kwm Exp $
#

PORTNAME=	gucharmap
PORTVERSION=	3.2.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Unicode/ISO10646 character map and font viewer

CONFLICTS=	gucharmap-2.[0-9]*

LATEST_LINK=	gucharmap3
USE_XZ=		yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gtk30 gnomedocutils gconf2
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gucharmap.schemas

.include <bsd.port.mk>
