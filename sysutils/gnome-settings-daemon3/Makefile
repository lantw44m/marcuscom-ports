# New ports collection makefile for:	gnome-settings-daemon
# Date created:				14 Jan 2008
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-settings-daemon3/Makefile,v 1.5 2010/12/27 14:37:53 kwm Exp $
#

PORTNAME=	gnome-settings-daemon
PORTVERSION=	2.91.8
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 settings daemon

BUILD_DEPENDS=	${LOCALBASE}/libexec/gnome-session-is-accelerated:${PORTSDIR}/x11/gnome-session3 \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3 \
		polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit \
		notify.1:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	${LOCALBASE}/libexec/gnome-session-is-accelerated:${PORTSDIR}/x11/gnome-session3 \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

LATEST_LINK=	gnome-settings-daemon3
USE_XORG=	xxf86misc
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomedesktop3 libgnomekbd3
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	PULSEAUDIO "Enable Pulseaudio support" On

GLIB_SCHEMAS=	org.gnome.settings-daemon.enums.xml \
		org.gnome.settings-daemon.peripherals.gschema.xml \
		org.gnome.settings-daemon.peripherals.wacom.gschema.xml \
		org.gnome.settings-daemon.plugins.gschema.xml \
		org.gnome.settings-daemon.plugins.housekeeping.gschema.xml \
		org.gnome.settings-daemon.plugins.keyboard.gschema.xml \
		org.gnome.settings-daemon.plugins.media-keys.gschema.xml \
		org.gnome.settings-daemon.plugins.power.gschema.xml \
		org.gnome.settings-daemon.plugins.xrandr.gschema.xml \
		org.gnome.settings-daemon.plugins.xsettings.gschema.xml

MAN1=		gnome-settings-daemon.1

.include <bsd.port.options.mk>

.if defined(WITHOUT_PULSEAUDIO)
CONFIGURE_ARGS+=--disable-pulse
PLIST_SUB+=	PULSEAUDIO="@comment "
.else
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=--enable-pulse
PLIST_SUB+=	PULSEAUDIO=""
.endif

.include <bsd.port.mk>
