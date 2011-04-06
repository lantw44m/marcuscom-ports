# New ports collection makefile for:	gnome2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome3/Makefile,v 1.20 2011/04/01 15:53:32 kwm Exp $
#

PORTNAME=	gnome3
PORTVERSION=	2.91.93
PORTREVISION?=	0
CATEGORIES?=	x11 gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	The "meta-port" for the GNOME 3 integrated X11 desktop

CONFLICTS?=	gnome3-lite-[0-9]*

RUN_DEPENDS?=	gnome-panel>=2.91.0:${PORTSDIR}/x11/gnome-panel3 \
		dconf:${PORTSDIR}/devel/dconf \
		gnome-session>=2.91.0:${PORTSDIR}/x11/gnome-session3 \
		gnome-themes-standard>=2.91.0:${PORTSDIR}/x11-themes/gnome-themes-standard \
		gnome-keyring>=2.91.0:${PORTSDIR}/security/gnome-keyring3 \
		gnome-power-manager>=2.91.0:${PORTSDIR}/sysutils/gnome-power-manager3 \
		gnome-mount:${PORTSDIR}/sysutils/gnome-mount \
		nautilus>=2.91.0:${PORTSDIR}/x11-fm/nautilus3 \
		${LOCALBASE}/lib/X11/fonts/bitstream-vera/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera \
		${LOCALBASE}/share/hal/fdi/information/10freedesktop/10-camera-ptp.fdi:${PORTSDIR}/sysutils/hal-info \
		yelp>=2.91.0:${PORTSDIR}/x11/yelp3 \
		zenity>=2.91.0:${PORTSDIR}/x11/zenity \
		metacity>=2.30.0:${PORTSDIR}/x11-wm/metacity \
		gnome-control-center>=2.91.0:${PORTSDIR}/sysutils/gnome-control-center3 \
		${LOCALBASE}/share/gnome-background-properties/gnome-nature.xml:${PORTSDIR}/x11-themes/gnome-backgrounds \
		gnome-tweak-tool:${PORTSDIR}/deskutils/gnome-tweak-tool \
		${LOCALBASE}/share/gnome/help/gnome-help/C/index.page:${PORTSDIR}/misc/gnome-user-docs3 \
		${LOCALBASE}/share/sounds/freedesktop/index.theme:${PORTSDIR}/audio/freedesktop-sound-theme

NO_BUILD=	yes

OPTIONS=	GNOME_SHELL "Build Gnome-shell (pulls in libxul)" off

.if ${.CURDIR:T}!="gnome3-lite"
OPTIONS+=	MAPI "Depend on evolution-mapi (pulls in samba4)" on
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_GNOME_SHELL)
RUN_DEPENDS+=	gnome-shell>=2.91.0:${PORTSDIR}/x11/gnome-shell
.endif

.if ${.CURDIR:T}!="gnome3-lite"
RUN_DEPENDS+=	empathy>=2.91.0:${PORTSDIR}/net-im/empathy3 \
		epiphany>=2.91.0:${PORTSDIR}/www/epiphany3 \
		epiphany-extensions>=2.91.0:${PORTSDIR}/www/epiphany-extensions3 \
		gnome-screensaver>=2.91.0:${PORTSDIR}/x11/gnome-screensaver3 \
		gucharmap>=2.33.0:${PORTSDIR}/deskutils/gucharmap3 \
		brasero>=2.91.0:${PORTSDIR}/sysutils/brasero3 \
		eog>=2.91.0:${PORTSDIR}/graphics/eog3 \
		eog-plugins>=2.91.0:${PORTSDIR}/graphics/eog-plugins3 \
		gedit>=2.91.0:${PORTSDIR}/editors/gedit3 \
		gedit-plugins>=2.91.0:${PORTSDIR}/editors/gedit-plugins3 \
		gnome-terminal>=2.33.0:${PORTSDIR}/x11/gnome-terminal3 \
		mousetweaks>=2.91.0:${PORTSDIR}/accessibility/mousetweaks3 \
		brasero>=2.91.0:${PORTSDIR}/sysutils/brasero3 \
		gcalctool>=2.91.0:${PORTSDIR}/math/gcalctool3 \
		gnome-utils>=2.91.0:${PORTSDIR}/deskutils/gnome-utils3 \
		gnome-system-monitor>=2.99.0:${PORTSDIR}/sysutils/gnome-system-monitor3 \
		file-roller>=2.91.0:${PORTSDIR}/archivers/file-roller3 \
		evince>=2.91.0:${PORTSDIR}/graphics/evince3 \
		vino>=2.91.0:${PORTSDIR}/net/vino3 \
		vinagre>=2.91.0:${PORTSDIR}/net/vinagre3 \
		gnome-games>=2.91.90:${PORTSDIR}/games/gnome-games3 \
		totem>=2.91.0:${PORTSDIR}/multimedia/totem3 \
		gconf-editor>=2.91.0:${PORTSDIR}/sysutils/gconf-editor3 \
		gdm>=2.91.0:${PORTSDIR}/x11/gdm3 \
		evolution>=2.91.0:${PORTSDIR}/mail/evolution3 \
		evolution-exchange>=2.91.0:${PORTSDIR}/mail/evolution-exchange3 \
		${LOCALBASE}/lib/gtk-3.0/modules/libatk-bridge.so:${PORTSDIR}/accessibility/at-spi2-atk

.if ${OSVERSION}>=800000
RUN_DEPENDS+=	cheese>=2.91.0:${PORTSDIR}/multimedia/cheese3
.endif

.if defined(WITH_MAPI)
RUN_DEPENDS+=	evolution-mapi>=2.91.0:${PORTSDIR}/mail/evolution-mapi3
.endif
.endif # !gnome3-lite section

do-install:	# empty

.include <bsd.port.post.mk>
