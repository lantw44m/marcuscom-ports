# New ports collection makefile for:   drwright
# Date Created:			26 Apr 2011
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	drwright
PORTVERSION=	3.2.5
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 RSI prevention tool

LIB_DEPENDS=	canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3 \
		notify.4:${PORTSDIR}/devel/libnotify

USE_XZ=		yes
USE_GNOME=	gnomehack intlhack gtk30 gnomecontrolcenter3
USE_XORG=	x11 xscrnsaver
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.settings-daemon.plugins.typing-break.gschema.xml

.include <bsd.port.mk>
