# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/gnome-session/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-session
PORTVERSION=	2.32.1
PORTREVISION=	3
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the GNOME 2 desktop

CONFLICTS=	gnome-session-3.[0-9]*

BUILD_DEPENDS=	${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon
LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring \
		notify:${PORTSDIR}/devel/libnotify \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		upower-glib:${PORTSDIR}/sysutils/upower
RUN_DEPENDS=	${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon \
    		${LOCALBASE}/sbin/console-kit-daemon:${PORTSDIR}/sysutils/consolekit \
		${LOCALBASE}/bin/xdpyinfo:${PORTSDIR}/x11/xdpyinfo

NO_STAGE=	yes
INSTALLS_ICONS=	yes
USES=		gettext gmake pathfix pkgconfig
USE_BZIP2=	yes
USE_XORG=	ice sm xau xrandr
USE_GNOME=	gnomeprefix intlhack gconf2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docbook-docs
# us gconftool-2 instead of sanity-check because that got removed from gconf2.
CONFIGURE_ENV=	ac_cv_path_GCONF_SANITY_CHECK=${LOCALBASE}/bin/gconftool-2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gnome-session.1 gnome-wm.1 gnome-session-properties.1 \
		gnome-session-save.1
GCONF_SCHEMAS=	gnome-session.schemas

.include <bsd.port.mk>
