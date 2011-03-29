# New ports collection makefile for:   gnome-shell
# Date created:        14 Aug 2009
# Whom:                Pawel Worach <pawel.worach@gmail.com>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-shell/Makefile,v 1.31 2011/03/25 19:38:21 kwm Exp $
#

PORTNAME=	gnome-shell
PORTVERSION=	2.91.93
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Next generation GNOME desktop shell

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		mutter.0:${PORTSDIR}/x11-wm/mutter \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib \
		telepathy-logger.2:${PORTSDIR}/net-im/telepathy-logger \
		pulse.0:${PORTSDIR}/audio/pulseaudio \
		croco-0.6.3:${PORTSDIR}/textproc/libcroco \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		clutter-glx-1.0:${PORTSDIR}/graphics/clutter \
		gjs-gi:${PORTSDIR}/lang/gjs
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus
#    		glxinfo:${PORTSDIR}/graphics/mesa-demos

USE_BZIP2=	yes
USE_XORG=	x11 xfixes sm
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gnomehack intlhack gtk30 gconf2 gnomemenus \
		gnomedesktop3 evolutiondataserver3 ltverhack
USE_GSTREAMER=	theora vp8 ogg
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.shell.gschema.xml
GCONF_SCHEMAS=	gnome-shell.schemas

MAN1=		gnome-shell.1

CONFIGURE_ARGS+=--enable-compile-warnings=no

post-patch:
	@${REINPLACE_CMD} -e 's|applications.menu|gnome-applications.menu|g' \
		${WRKSRC}/src/shell-app-system.c

.include <bsd.port.mk>
