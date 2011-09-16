# New ports collection makefile for:	gnome-settings-daemon
# Date created:				14 Jan 2008
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-settings-daemon3/Makefile,v 1.24 2011/05/24 16:55:18 kwm Exp $
#

PORTNAME=	gnome-settings-daemon
PORTVERSION=	3.1.91
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 settings daemon

BUILD_DEPENDS=	gnome-session>=2.91.0:${PORTSDIR}/x11/gnome-session3 \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3 \
		polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit \
		colord.1:${PORTSDIR}/graphics/colord \
		notify.4:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	gnome-session>=2.91.0:${PORTSDIR}/x11/gnome-session3 \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

CONFLICTS=	gnome-settings-daemon-2.[0-9]*

LATEST_LINK=	gnome-settings-daemon3
USE_XORG=	xxf86misc
USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomedesktop3 libgnomekbd3
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--with-pnpids=${LOCALBASE}/share/libgnome-desktop-3.0/pnp.ids
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	PULSEAUDIO "Enable Pulseaudio support" On \
		CUPS "Enable cups (printing) support" On \
		SMARTCARD "Enable smartcard support" On

GLIB_SCHEMAS=	org.gnome.settings-daemon.enums.xml \
		org.gnome.settings-daemon.peripherals.gschema.xml \
		org.gnome.settings-daemon.peripherals.wacom.gschema.xml \
		org.gnome.settings-daemon.plugins.color.gschema.xml \
		org.gnome.settings-daemon.plugins.gschema.xml \
		org.gnome.settings-daemon.plugins.housekeeping.gschema.xml \
		org.gnome.settings-daemon.plugins.keyboard.gschema.xml \
		org.gnome.settings-daemon.plugins.media-keys.gschema.xml \
		org.gnome.settings-daemon.plugins.power.gschema.xml \
		org.gnome.settings-daemon.plugins.print-notifications.gschema.xml \
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

.if defined(WITH_CUPS)
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-client
PLIST_SUB+=	CUPS=""
.else
PLIST_SUB+=	CUPS="@comment "
CONFIGURE_ARGS+=--disable-cups
.endif

.if defined(WITHOUT_SMARTCARD)
CONFIGURE_ARGS+=--disable-smartcard-support
PLIST_SUB+=	SMARTCARD="@comment "
.else
LIB_DEPENDS+=	nss3.1:${PORTSDIR}/security/nss
CONFIGURE_ARGS+=--enable-smartcard-support
PLIST_SUB+=	SMARTCARD=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/gnome|${PREFIX}/etc/gnome|g' \
		${WRKSRC}/data/org.gnome.settings-daemon.plugins.xrandr.gschema.xml.in.in

.include <bsd.port.mk>
