# New ports collection makefile for:	gucharmap
# Date created:				02 Mar 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/gucharmap/Makefile,v 1.43 2007/12/23 09:28:04 kwm Exp $
#

PORTNAME=	gucharmap
PORTVERSION=	2.21.5
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Unicode/ISO10646 character map and font viewer

LIB_DEPENDS=	rarian.0:${PORTSDIR}/textproc/rarian

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gtk20 gnomedocutils
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
	       	LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gucharmap.schemas

.include <bsd.port.mk>
