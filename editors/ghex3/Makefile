# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/editors/ghex3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	ghex
PORTVERSION=	3.4.1
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 hex editor

CONFLICT=	ghex-2.\*

USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gtk30 gnomedocutils
INSTALLS_OMF=	yes
USES=		gettext pathfix pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.GHex.gschema.xml

.include <bsd.port.mk>
