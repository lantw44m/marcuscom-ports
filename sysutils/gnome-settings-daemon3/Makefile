# New ports collection makefile for:	gnome-settings-daemon
# Date created:				14 Jan 2008
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-settings-daemon/Makefile,v 1.65 2010/06/10 14:27:22 kwm Exp $
#

PORTNAME=	gnome-settings-daemon
PORTVERSION=	2.31.5.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 settings daemon

LIB_DEPENDS=	pulse.0:${PORTSDIR}/audio/pulseaudio \
		canberra-gtk.0:${PORTSDIR}/audio/libcanberra \
		polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit \
		notify.1:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	xrdb:${PORTSDIR}/x11/xrdb

LATEST_LINK=	gnome-settings-daemon3
USE_XORG=	xxf86misc
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomedesktop3 libgnomekbd
USE_GETTEXT=	yes
USE_GSTREAMER=	good
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	apps_gnome_settings_daemon_housekeeping.schemas \
		apps_gnome_settings_daemon_keybindings.schemas \
		apps_gnome_settings_daemon_xrandr.schemas \
		desktop_gnome_font_rendering.schemas \
		desktop_gnome_keybindings.schemas \
		desktop_gnome_peripherals_smartcard.schemas \
		desktop_gnome_peripherals_touchpad.schemas \
		gnome-settings-daemon.schemas

.include <bsd.port.mk>
