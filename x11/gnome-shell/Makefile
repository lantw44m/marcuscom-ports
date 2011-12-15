# New ports collection makefile for:   gnome-shell
# Date created:        14 Aug 2009
# Whom:                Pawel Worach <pawel.worach@gmail.com>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-shell/Makefile,v 1.46 2011/11/12 14:54:38 kwm Exp $
#

PORTNAME=	gnome-shell
PORTVERSION=	3.2.1
PORTREVISION=	4
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Next generation GNOME desktop shell

BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		caribou.0:${PORTSDIR}/accessibility/caribou \
		mutter.0:${PORTSDIR}/x11-wm/mutter \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib \
		telepathy-logger.2:${PORTSDIR}/net-im/telepathy-logger \
		folks.25:${PORTSDIR}/net-im/folks \
		pulse.0:${PORTSDIR}/audio/pulseaudio \
		croco-0.6.3:${PORTSDIR}/textproc/libcroco \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		clutter-glx-1.0:${PORTSDIR}/graphics/clutter \
		gjs.0:${PORTSDIR}/lang/gjs
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

USE_XZ=		yes
USE_XORG=	x11 xfixes sm
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gnomehack intlhack gtk30 gconf2 gnomemenus3 \
		gnomedesktop3 evolutiondataserver3 ltverhack
USE_GSTREAMER=	theora vp8 ogg
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.shell.gschema.xml
GCONF_SCHEMAS=	gnome-shell.schemas

MAN1=		gnome-shell.1

CONFIGURE_ARGS+=--enable-compile-warnings=no \
		--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt

post-patch:
	@${REINPLACE_CMD} -e 's|applications.menu|gnome-applications.menu|g' \
		${WRKSRC}/src/shell-app-system.c
	@${REINPLACE_CMD} -e 's|libnm-glib libnm-util ||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|UBDIRS = data js src browser-plugin|UBDIRS = data js src|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
