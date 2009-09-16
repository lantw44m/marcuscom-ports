# New ports collection makefile for:   gnome-shell
# Date created:        14 Aug 2009
# Whom:                Pawel Worach <pawel.worach@gmail.com>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-shell/Makefile,v 1.3 2009/09/05 12:36:24 kwm Exp $
#

PORTNAME=	gnome-shell
PORTVERSION=	2.27.3
CATEGORIES=	x11
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Next generation GNOME desktop shell

BUILD_DEPENDS=	${LOCALBASE}/share/gir-1.0/Gtk-2.0.gir:${PORTSDIR}/x11-toolkits/gir-repository-gtk20
LIB_DEPENDS=	girepository-1.0:${PORTSDIR}/devel/gobject-introspection \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		mutter-private.0:${PORTSDIR}/x11-wm/mutter \
		clutter-glx-1.0:${PORTSDIR}/graphics/clutter \
		gjs-gi:${PORTSDIR}/lang/gjs
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus

USE_BZIP2=	yes
USE_XORG=	x11 xfixes sm
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomeprefix gnomehack intlhack gtk20 gconf2 gnomemenus \
		gnomedesktop ltverhack libgnomeui librsvg2
USE_GSTREAMER=	theora
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I/usr/local/include/js -I/usr/local/include/nspr"

GCONF_SCHEMAS=	gnome-shell.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/bin/python|/usr/bin/env python|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/gnome-shell.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
