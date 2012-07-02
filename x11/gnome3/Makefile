# New ports collection makefile for:	gnome2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome3/Makefile,v 1.36 2012/06/29 13:58:19 kwm Exp $
#

PORTNAME=	gnome3
PORTVERSION=	3.2.0
PORTREVISION?=	1
CATEGORIES?=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	The "meta-port" for the GNOME 3 integrated X11 desktop

CONFLICTS?=	gnome2-[0-9]* gnome2-lite-[0-9]* gnome3-lite-[0-9]*

RUN_DEPENDS?=	gnome-panel>=3.0.0:${PORTSDIR}/x11/gnome-panel3 \
		dconf:${PORTSDIR}/devel/dconf \
		gnome-session>=3.0.0:${PORTSDIR}/x11/gnome-session3 \
		gnome-themes-standard>=3.0.0:${PORTSDIR}/x11-themes/gnome-themes-standard \
		gnome-icon-theme-extras>=3.0.0:${PORTSDIR}/misc/gnome-icon-theme-extras \
		gnome-icon-theme-symbolic>=3.0.0:${PORTSDIR}/x11-themes/gnome-icon-theme-symbolic \
		gnome-keyring>=3.0.0:${PORTSDIR}/security/gnome-keyring3 \
		gnome-power-manager>=3.0.0:${PORTSDIR}/sysutils/gnome-power-manager3 \
		orca>=3.0.0:${PORTSDIR}/accessibility/orca3 \
		gnome-mount:${PORTSDIR}/sysutils/gnome-mount \
		nautilus>=3.0.0:${PORTSDIR}/x11-fm/nautilus3 \
		${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera \
		${LOCALBASE}/share/hal/fdi/information/10freedesktop/10-camera-ptp.fdi:${PORTSDIR}/sysutils/hal-info \
		yelp>=3.0.0:${PORTSDIR}/x11/yelp3 \
		zenity>=3.0.0:${PORTSDIR}/x11/zenity \
		seahorse>=3.0.0:${PORTSDIR}/security/seahorse3 \
		metacity>=2.34.0:${PORTSDIR}/x11-wm/metacity3 \
		gnome-control-center>=3.0.0:${PORTSDIR}/sysutils/gnome-control-center3 \
		${LOCALBASE}/share/gnome-background-properties/gnome-backgrounds.xml:${PORTSDIR}/x11-themes/gnome-backgrounds \
		${LOCALBASE}/share/help/C/gnome-help/index.page:${PORTSDIR}/misc/gnome-user-docs3 \
		${LOCALBASE}/share/sounds/freedesktop/index.theme:${PORTSDIR}/audio/freedesktop-sound-theme

NO_BUILD=	yes

OPTIONS=	GNOME_SHELL "Build Gnome-shell (pulls in libxul)" off

.if ${.CURDIR:T}!="gnome3-lite"
#OPTIONS+=	MAPI "Depend on evolution-mapi (pulls in samba4)" off
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_GNOME_SHELL)
RUN_DEPENDS+=	gnome-shell>=3.0.0:${PORTSDIR}/x11/gnome-shell \
		gnome-tweak-tool:${PORTSDIR}/deskutils/gnome-tweak-tool
.endif

.if ${.CURDIR:T}!="gnome3-lite"
RUN_DEPENDS+=	empathy>=3.0.0:${PORTSDIR}/net-im/empathy3 \
		epiphany>=3.0.0:${PORTSDIR}/www/epiphany3 \
		epiphany-extensions>=3.0.0:${PORTSDIR}/www/epiphany-extensions3 \
		gnome-screensaver>=3.0.0:${PORTSDIR}/x11/gnome-screensaver3 \
		gucharmap>=3.0.0:${PORTSDIR}/deskutils/gucharmap3 \
		eog>=3.0.0:${PORTSDIR}/graphics/eog3 \
		eog-plugins>=3.0.0:${PORTSDIR}/graphics/eog-plugins3 \
		gedit>=3.0.0:${PORTSDIR}/editors/gedit3 \
		gedit-plugins>=3.0.0:${PORTSDIR}/editors/gedit-plugins3 \
		gnome-terminal>=3.0.0:${PORTSDIR}/x11/gnome-terminal3 \
		mousetweaks>=3.0.0:${PORTSDIR}/accessibility/mousetweaks3 \
		brasero>=3.0.0:${PORTSDIR}/sysutils/brasero3 \
		gcalctool>=3.0.0:${PORTSDIR}/math/gcalctool3 \
		baobab>=3.4.0:${PORTSDIR}/deskutils/baobab \
		gnome-dictionary>=3.4.0:${PORTSDIR}/deskutils/gnome-dictionary \
		gnome-font-viewer>=3.4.0:${PORTSDIR}/deskutils/gnome-font-viewer \
		gnome-screenshot>=3.4.0:${PORTSDIR}/deskutils/gnome-screenshot \
		gnome-search-tool>=3.4.0:${PORTSDIR}/deskutils/gnome-search-tool \
		gnome-system-log>=3.4.0:${PORTSDIR}/deskutils/gnome-system-log \
		gnome-system-monitor>=3.0.0:${PORTSDIR}/sysutils/gnome-system-monitor3 \
		file-roller>=3.0.0:${PORTSDIR}/archivers/file-roller3 \
		evince>=3.0.0:${PORTSDIR}/graphics/evince3 \
		vino>=3.0.0:${PORTSDIR}/net/vino3 \
		vinagre>=3.0.0:${PORTSDIR}/net/vinagre3 \
		gnome-games>=3.0.0:${PORTSDIR}/games/gnome-games3 \
		totem>=3.0.0:${PORTSDIR}/multimedia/totem3 \
		gconf-editor>=3.0.0:${PORTSDIR}/sysutils/gconf-editor3 \
		gdm>=3.0.0:${PORTSDIR}/x11/gdm3 \
		evolution>=3.0.0:${PORTSDIR}/mail/evolution3 \
		evolution-exchange>=3.0.0:${PORTSDIR}/mail/evolution-exchange3 \
		${LOCALBASE}/lib/gtk-3.0/modules/libatk-bridge.so:${PORTSDIR}/accessibility/at-spi2-atk

.if ${OSVERSION}>=800000
RUN_DEPENDS+=	cheese>=3.0.0:${PORTSDIR}/multimedia/cheese3
.endif

.if defined(WITH_MAPI)
RUN_DEPENDS+=	evolution-mapi>=3.0.0:${PORTSDIR}/mail/evolution-mapi3
.endif
.endif # !gnome3-lite section

do-install:	# empty

.include <bsd.port.post.mk>
