# New ports collection makefile for:	vino
# Date created:				16 July 2004
# Whom:					Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $MCom: ports/net/vino/Makefile,v 1.83 2011/03/07 08:48:34 kwm Exp $
#

PORTNAME=	vino
PORTVERSION=	2.99.3
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC server that allows for remote access to your GNOME desktop

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib \
		gnome-keyring.0:${PORTSDIR}/security/libgnome-keyring \
		avahi-glib.1:${PORTSDIR}/net/avahi-app \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gtk30
USE_XORG=	xdamage xfixes xtst
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=3
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--without-network-manager \
		--disable-http-server 
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=	notify.4:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--without-libnotify
.endif

.include <bsd.port.mk>
