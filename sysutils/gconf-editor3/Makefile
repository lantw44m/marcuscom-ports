# New ports collection makefile for:	gconf-editor
# Date created:				12 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gconf-editor3/Makefile,v 1.3 2011/04/25 19:45:50 mezz Exp $
#

PORTNAME=	gconf-editor
PORTVERSION=	3.0.0
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A gconf database editor for the GNOME 3 environment

CONFLICTS=	gconf-editor-2.[0-9]*

LATEST_LINK=	gconf-editor3
USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gtk30 gconf2 gnomedocutils
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gconf-editor.1
GCONF_SCHEMAS=	gconf-editor.schemas

.include <bsd.port.mk>
