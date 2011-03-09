# New ports collection makefile for:   gnome-shell
# Date created:        14 Aug 2009
# Whom:                Pawel Worach <pawel.worach@gmail.com>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-shell/Makefile,v 1.26 2011/03/09 10:47:59 kwm Exp $
#

PORTNAME=	gnome-shell
PORTVERSION=	2.91.91
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Next generation GNOME desktop shell

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		mutter-private.0:${PORTSDIR}/x11-wm/mutter \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib \
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
USE_GSTREAMER=	theora
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.shell.gschema.xml
GCONF_SCHEMAS=	gnome-shell.schemas

MAN1=		gnome-shell.1

CONFIGURE_ARGS+=--enable-compile-warnings=no

.include <bsd.port.mk>
