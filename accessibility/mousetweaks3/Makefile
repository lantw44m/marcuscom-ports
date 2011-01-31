# Ports collection makefile for:	mousetweaks
# Date created:			2008 01 10
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/mousetweaks/Makefile,v 1.53 2010/11/15 21:25:36 kwm Exp $
#

PORTNAME=	mousetweaks
PORTVERSION=	2.91.6
CATEGORIES=	accessibility
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mouse accessibility enhancements for the GNOME desktop

BUILD_DEPENDS=	gsettings-desktop-schemas>=0.1.0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gsettings-desktop-schemas>=0.1.0:${PORTSDIR}/devel/gsettings-desktop-schemas

USE_XORG=	x11 xfixes xcursor xtst
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GLIB_SCHEMAS=	org.gnome.mousetweaks.enums.xml \
		org.gnome.mousetweaks.gschema.xml
MAN1=		mousetweaks.1

#OPTIONS=	APPLETS "Build dwell-click and pointer-capture applets" on

.include <bsd.port.options.mk>

#.if defined(WITH_APPLETS)
#USE_GNOME+=	gnomepanel3
#CONFIGURE_ARGS+=--enable-pointer-capture \
#		--enable-dwell-click
#MAN1=		dwell-click-applet.1 pointer-capture-applet.1
#PLIST_SUB+=	APPLETS=""
#.else
PLIST_SUB+=	APPLETS="@comment "
#.endif

.include <bsd.port.mk>
