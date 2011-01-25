# New ports collection makefile for:	gnome2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	gnome3
PORTVERSION=	2.32.1
PORTREVISION?=	0
CATEGORIES?=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	The "meta-port" for the GNOME 3 integrated X11 desktop

RUN_DEPENDS?=	gnome-panel>=2.91.0:${PORTSDIR}/x11/gnome-panel3 \
		eog>=2.91.0:${PORTSDIR}/graphics/eog3 \
		gedit>=2.91.0:${PORTSDIR}/editors/gedit3 \
		zenity>=2.91.0:${PORTSDIR}/x11/zenity3 \
		metacity:${PORTSDIR}/x11-wm/metacity \
		gnome-terminal>=2.33.0:${PORTSDIR}/x11/gnome-terminal3 \
		gnome-session>=2.91.0:${PORTSDIR}/x11/gnome-session3 \
		nautilus>=2.91.0:${PORTSDIR}/x11-fm/nautilus3 \
		file-roller>=2.91.0:${PORTSDIR}/archivers/file-roller3 \
		${LOCALBASE}/share/themes/Glider/gtk-3.0/gtkrc:${PORTSDIR}/x11-themes/gnome-themes3 \
		${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera \
		${LOCALBASE}/lib/gstreamer-0.10/.gstreamer-plugins-core.keep:${PORTSDIR}/multimedia/gstreamer-plugins-core \
		${LOCALBASE}/lib/gstreamer-0.10/libgstgconfelements.so:${PORTSDIR}/devel/gstreamer-plugins-gconf \
		gnome-control-center>=2.91.0:${PORTSDIR}/sysutils/gnome-control-center3 \
		${LOCALBASE}/share/gnome-background-properties/gnome-nature.xml:${PORTSDIR}/x11-themes/gnome-backgrounds \
		evince>=2.91.0:${PORTSDIR}/graphics/evince3 \
		gnome-mount:${PORTSDIR}/sysutils/gnome-mount \
		${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon \
		${LOCALBASE}/share/hal/fdi/information/10freedesktop/10-camera-ptp.fdi:${PORTSDIR}/sysutils/hal-info \
		${LOCALBASE}/share/sounds/freedesktop/index.theme:${PORTSDIR}/audio/freedesktop-sound-theme

NO_BUILD=	yes

.if !defined(GNOME_SLAVE)
USE_PYTHON=	yes
.endif

.if !defined(GNOME_SLAVE) || ${.CURDIR:T}=="gnome2-lite"
#OPTIONS=	XSCREENSAVER "Use xscreensaver as screen saver app" off \
#		MAPI "Depend on evolution-mapi (pulls in samba4)" on
.endif

do-install:	# empty

.include <bsd.port.pre.mk>

.if !defined(GNOME_SLAVE)
.if ${ARCH}!="sparc64" && ${ARCH}!="ia64"
RUN_DEPENDS+=	yelp>=2.91.0:${PORTSDIR}/x11/yelp3 \
#		epiphany:${PORTSDIR}/www/epiphany
.endif
#.if ${.CURDIR:T}!="gnome2-lite"
#RUN_DEPENDS+=	empathy:${PORTSDIR}/net-im/empathy \
#		gucharmap:${PORTSDIR}/deskutils/gucharmap \
#		sound-juicer:${PORTSDIR}/audio/sound-juicer \
#		zenity:${PORTSDIR}/x11/zenity \
#		gnome-nettool:${PORTSDIR}/net/gnome-nettool \
#		vinagre:${PORTSDIR}/net/vinagre \
#		brasero:${PORTSDIR}/sysutils/brasero \
#		gnome-file-share-properties:${PORTSDIR}/www/gnome-user-share \
#		${LOCALBASE}/libexec/deskbar-applet/deskbar-applet:${PORTSDIR}/deskutils/deskbar-applet \
#		${LOCALBASE}/lib/hamster-applet/hamster-applet:${PORTSDIR}/deskutils/hamster-applet \
#		${LOCALBASE}/lib/gtk-2.0/modules/libatk-bridge.so:${PORTSDIR}/accessibility/at-spi \
#		gpk-application:${PORTSDIR}/ports-mgmt/gnome-packagekit \
#		ekiga:${PORTSDIR}/net/ekiga3
.if ${OSVERSION}>=800000
#RUN_DEPENDS+=	cheese:${PORTSDIR}/multimedia/cheese
.endif
#.if ${ARCH} == "i386"
#RUN_DEPENDS+=	tomboy:${PORTSDIR}/deskutils/tomboy
#.endif
#.if defined(WITH_MAPI)
#RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/libexchangemapi-1.0.pc:${PORTSDIR}/mail/evolution-mapi
#.endif
#.endif
.endif

.if ${.CURDIR}==${MASTERDIR} || ${.CURDIR:T}=="gnome2-lite"
.if defined(WITH_XSCREENSAVER)
#RUN_DEPENDS+=	${LOCALBASE}/share/applications/xscreensaver-properties.desktop:${PORTSDIR}/x11/xscreensaver-gnome
.else
#RUN_DEPENDS+=	gnome-screensaver:${PORTSDIR}/x11/gnome-screensaver
.endif
.endif

.include <bsd.port.post.mk>
