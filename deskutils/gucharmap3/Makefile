# New ports collection makefile for:	gucharmap
# Date created:				02 Mar 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/gucharmap3/Makefile,v 1.3 2011/04/17 19:14:30 mezz Exp $
#

PORTNAME=	gucharmap
PORTVERSION=	3.0.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Unicode/ISO10646 character map and font viewer

CONFLICTS=	gucharmap-2.[0-9]*

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gtk30 gnomedocutils gconf2
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
	       	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gtk=3.0

GCONF_SCHEMAS=	gucharmap.schemas

.include <bsd.port.mk>
