# New ports collection makefile for:	ghex2
# Date created:				15 September 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/editors/ghex3/Makefile,v 1.1 2011/10/15 16:35:05 kwm Exp $
#

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
USE_GNOME=	gnomeprefix gnomehack intlhack gtk30 gnomedocutils
INSTALLS_OMF=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.GHex.gschema.xml

.include <bsd.port.mk>
