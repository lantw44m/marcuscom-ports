# New ports collection makefile for:	gconf-editor
# Date created:				12 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	gconf-editor
PORTVERSION=	2.11.92
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.11
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A gconf database editor for the GNOME 2 environment

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gconf-editor.1
GCONF_SCHEMAS=	gconf-editor.schemas

.include <bsd.port.mk>
