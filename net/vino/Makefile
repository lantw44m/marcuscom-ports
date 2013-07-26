# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$
#   $MCom: ports/trunk/net/vino/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	vino
PORTVERSION=	2.32.2
PORTREVISION=	4
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC server that allows for remote access to your GNOME desktop

LIB_DEPENDS=	gnutls:${PORTSDIR}/security/gnutls \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib \
		unique-1.0:${PORTSDIR}/x11-toolkits/unique

CONFLICTS=	vino-3.[0-9]*

USE_BZIP2=	yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix intlhack gnomepanel
USE_XORG=	xtst
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	vino-server.schemas

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-libnotify=yes
.else
CONFIGURE_ARGS+=--enable-libnotify=no
.endif

.include <bsd.port.mk>
