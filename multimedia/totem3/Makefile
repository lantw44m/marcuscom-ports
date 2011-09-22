# New ports collection makefile for:    totem
# Date created:         17 Oct 2002
# Whom:                 Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#   $MCom: ports/multimedia/totem3/Makefile,v 1.19 2011/09/18 15:36:58 kwm Exp $
#

PORTNAME=	totem
PORTVERSION=	3.1.92
PORTREVISION?=	0
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	A gstreamer-based video player for the GNOME 3 Desktop

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	gdata.13:${PORTSDIR}/devel/libgdata \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		clutter-gst-1.0.0:${PORTSDIR}/multimedia/clutter-gst \
		peas-1.0.0:${PORTSDIR}/devel/libpeas \
		totem-plparser.17:${PORTSDIR}/multimedia/totem-pl-parser
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme \
		gnome-settings-daemon>=2.91.0:${PORTSDIR}/sysutils/gnome-settings-daemon3 \
		gnome-icon-theme-symbolic>=2.91.0:${PORTSDIR}/x11-themes/gnome-icon-theme-symbolic

CONFLICTS=	totem-2.[0-9]*

LATEST_LINK=	totem3
USE_PYTHON=	yes
USE_XORG=	x11 xrandr xxf86vm
USE_XZ=		yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack desktopfileutils \
		nautilus3 ltverhack pygobject3 gnomedocutils
USE_GSTREAMER=	core gconf hal good mpeg2dec soup ugly gio resindvd
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
	       	LIBS="-L${LOCALBASE}/lib -lXrandr" \
		BROWSER_PLUGIN_DIR="${WEBPLUGINS_DIR}"
CONFIGURE_ARGS=	--with-plugins="${TOTEM_PLUGINS}"

MAN1=		totem.1 totem-video-thumbnailer.1
GLIB_SCHEMAS=	org.gnome.totem.enums.xml \
		org.gnome.totem.gschema.xml \
		org.gnome.totem.plugins.opensubtitles.gschema.xml

OPTIONS=	LIRC "Enable lirc support" off \
		GALAGO "Enable Galago support" off \
		BROWSER_PLUGINS "Enable install plugins for gecko browser" on \
		PUBLISH "Enable Publish (network playlist) plugin" off \
#		TRACKER "Enable tracker local search plugin" off

# check configure script for allowed_plugins="..." for new plugins
TOTEM_PLUGINS=	thumbnail screensaver ontop gromit media-player-keys \
		properties skipto youtube opensubtitles screenshot \
		brasero-disc-recorder dbus-service iplayer

# Not using:
# TOTEM_PLUGINS= mythtv bemused jamendo
# coherence_upnp (uses py-gtk2 conflict with py-gobject >=2.27.0)

# current full list, needs sorting (again)
#allowed_plugins="bemused brasero-disc-recorder chapters coherence_upnp dbus-service galago gromit iplayer jamendo lirc media-player-keys ontop opensubtitles properties publish pythonconsole save-file sample-python screensaver screenshot sidebar-test skipto thumbnail tracker youtube"

.include <bsd.port.pre.mk>

.if defined(WITH_PUBLISH)
LIB_DEPENDS+=	epc-1.0.2:${PORTSDIR}/www/libepc
PLIST_SUB+=	PUBLISH=""
TOTEM_PLUGINS:=	${TOTEM_PLUGINS} publish
.else
PLIST_SUB+=	PUBLISH="@comment "
.endif

#.if defined(WITH_TRACKER)
#LIB_DEPENDS+=	tracker-gtk.0:${PORTSDIR}/sysutils/tracker-libtrackergtk
#TOTEM_PLUGINS:=	${TOTEM_PLUGINS} tracker
#PLIST_SUB+=	TRACKER=""
#.else
PLIST_SUB+=	TRACKER="@comment "
#.endif

.if defined(WITH_LIRC)
LIB_DEPENDS+=	lirc_client.1:${PORTSDIR}/comms/lirc
PLIST_SUB+=	LIRC=""
TOTEM_PLUGINS:=	${TOTEM_PLUGINS} lirc
.else
PLIST_SUB+=	LIRC="@comment "
.endif

.if defined(WITH_GALAGO)
LIB_DEPENDS+=	galago.3:${PORTSDIR}/devel/libgalago
PLIST_SUB+=	GALAGO=""
TOTEM_PLUGINS:=	${TOTEM_PLUGINS} galago
.else
PLIST_SUB+=	GALAGO="@comment "
.endif

.if !defined(WITHOUT_BROWSER_PLUGINS)
CONFIGURE_ARGS+=--enable-browser-plugins \
		--enable-gmp-plugin \
		--enable-narrowspace-plugin
PLIST_SUB+=	BROWSER_PLUGINS=""

USE_WEBPLUGINS=		gecko19 webkit-gtk2
WEBPLUGINS_FILES=	libtotem-cone-plugin.so libtotem-gmp-plugin.so \
			libtotem-mully-plugin.so \
			libtotem-narrowspace-plugin.so
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
.else
CONFIGURE_ARGS+=--disable-browser-plugins \
		--disable-basic-plugin \
		--disable-gmp-plugin \
		--disable-narrowspace-plugin
PLIST_SUB+=	BROWSER_PLUGINS="@comment "
.endif

.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/acd0
.endif

pre-everything::
	@${ECHO_MSG} "===> The default DVD device is ${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"

post-patch:
	@${CP} -f ${FILESDIR}/pkg-message.in ${PKGMESSAGE}
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/src/backend/bacon-video-widget-gst-0.10.c

post-install:
	@-update-desktop-database
#	${MKDIR} ${PREFIX}/share/vala/vapi
#	${INSTALL_DATA} ${WRKSRC}/bindings/vala/totem.vapi ${PREFIX}/share/vala/vapi
#	${INSTALL_DATA} ${WRKSRC}/bindings/vala/totem.deps ${PREFIX}/share/vala/vapi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
