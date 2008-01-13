# Ports collection makefile for:	mousetweaks
# Date created:			2008 01 10
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$

PORTNAME=	mousetweaks
PORTVERSION=	0.2.8
CATEGORIES=	accessibility
MASTER_SITES=	https://launchpad.net/mousetweaks/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mouse accessibility enhancements for the GNOME desktop

USE_GNOME=	gnomehack gnomepanel
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
GCONF_SCHEMAS=	mousetweaks.schemas pointer-capture-applet.schemas

MAN1=		mousetweaks.1

.include <bsd.port.mk>
