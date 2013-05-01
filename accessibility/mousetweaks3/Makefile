# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/accessibility/mousetweaks3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	mousetweaks
PORTVERSION=	3.6.0
CATEGORIES=	accessibility
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mouse accessibility enhancements for the GNOME desktop

BUILD_DEPENDS=	gsettings-desktop-schemas>=0.1.0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gsettings-desktop-schemas>=0.1.0:${PORTSDIR}/devel/gsettings-desktop-schemas

CONFLICTS=	mousetweaks-2.[0-9]*

LATEST_LINK=	mousetweaks3
USE_XZ=		yes
USE_XORG=	x11 xfixes xcursor xtst
USE_GNOME=	gnomeprefix intlhack gtk30
USE_GMAKE=	yes
USES=		gettext pathfix pkgconfig
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.mousetweaks.enums.xml \
		org.gnome.mousetweaks.gschema.xml
MAN1=		mousetweaks.1

.include <bsd.port.mk>
