# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/deskutils/gucharmap/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	gucharmap
PORTVERSION=	2.32.1
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A Unicode/ISO10646 character map and font viewer

LIB_DEPENDS=	rarian:${PORTSDIR}/textproc/rarian

CONFLICTS=	gucharmap-3.[0-9]*

USE_BZIP2=	yes
USES=		gettext pathfix pkgconfig
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gtk20 gnomedocutils gconf2
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gucharmap.schemas

.include <bsd.port.mk>
