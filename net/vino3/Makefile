# New ports collection makefile for:	vino
# Date created:				16 July 2004
# Whom:					Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $MCom: ports/net/vino3/Makefile,v 1.7 2011/04/25 19:40:17 mezz Exp $
#

PORTNAME=	vino
PORTVERSION=	3.0.1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC server that allows for remote access to your GNOME desktop

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		soup-2.4.1:${PORTSDIR}/devel/libsoup \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring \
		avahi-glib.1:${PORTSDIR}/net/avahi-app

CONFLICTS=	vino-2.[0-9]*

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gtk30
USE_XORG=	xdamage xfixes xtst
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--without-network-manager \
		--disable-http-server 
CPPFLAGS=	"-I${LOCALBASE}/include"
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
GLIB_SCHEMAS=	org.gnome.Vino.enums.xml org.gnome.Vino.gschema.xml

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=	notify.4:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--without-libnotify
.endif

.include <bsd.port.mk>
