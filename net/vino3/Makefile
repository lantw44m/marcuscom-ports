# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$
#   $MCom: ports/trunk/net/vino3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	vino
PORTVERSION=	3.6.2
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC server that allows for remote access to your GNOME desktop

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		soup-2.4:${PORTSDIR}/devel/libsoup \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring \
		avahi-glib:${PORTSDIR}/net/avahi-app

CONFLICTS=	vino-2.[0-9]*

LATEST_LINK=	vino3
USE_XZ=		yes
USES=		gettext gmake pathfix
USE_GNOME=	gnomeprefix gtk30 intlhack
USE_XORG=	xdamage xfixes xtst
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--without-network-manager \
		--disable-http-server
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.Vino.enums.xml org.gnome.Vino.gschema.xml

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--without-libnotify
.endif

.include <bsd.port.mk>
