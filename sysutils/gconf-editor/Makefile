# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/gconf-editor/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gconf-editor
PORTVERSION=	2.32.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A gconf database editor for the GNOME 2 environment

CONFLICTS=	gconf-editor-3.[0-9]*

USE_BZIP2=	yes
USES=		gettext gmake pathfix pkgconfig
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intlhack libgnomeui gnomedocutils
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gconf-editor.1
GCONF_SCHEMAS=	gconf-editor.schemas

.include <bsd.port.mk>
