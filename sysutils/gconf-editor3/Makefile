# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/gconf-editor3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gconf-editor
PORTVERSION=	3.0.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A gconf database editor for the GNOME 3 environment

CONFLICTS=	gconf-editor-2.[0-9]*

NO_STAGE=	yes
LATEST_LINK=	gconf-editor3
USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intlhack gtk30 gconf2 gnomedocutils
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gconf-editor.1
GCONF_SCHEMAS=	gconf-editor.schemas

.include <bsd.port.mk>
