# Ports collection makefile for:	mousetweaks
# Date created:			2008 01 10
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/mousetweaks/Makefile,v 1.44 2010/03/10 17:24:30 kwm Exp $
#

PORTNAME=	mousetweaks
PORTVERSION=	2.30.0
CATEGORIES=	accessibility
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mouse accessibility enhancements for the GNOME desktop

USE_XORG=	x11 xfixes xcursor xtst
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gnomepanel intlhack atspi
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	mousetweaks.schemas pointer-capture-applet.schemas
MAN1=		dwell-click-applet.1 mousetweaks.1 pointer-capture-applet.1

.include <bsd.port.mk>
