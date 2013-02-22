# New ports collection makefile for:   mutter
# Date created:        14 Aug 2009
# Whom:                Pawel Worach <pawel.worach@gmail.com>
#
# $FreeBSD$
#   $MCom: ports/x11-wm/mutter/Makefile,v 1.37 2013/01/09 18:52:22 kwm Exp $
#

PORTNAME=	mutter
PORTVERSION=	3.4.1
CATEGORIES=	x11-wm
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Window and compositing manager based on Clutter

BUILD_DEPENDS=	zenity>=3.0.0:${PORTSDIR}/x11/zenity3 \
		gsettings-desktop-schemas>=3.4.0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification \
		clutter-1.0:${PORTSDIR}/graphics/clutter \
		canberra-gtk3:${PORTSDIR}/audio/libcanberra-gtk3
RUN_DEPENDS=	zenity:${PORTSDIR}/x11/zenity \
		gsettings-desktop-schemas>=3.4.0:${PORTSDIR}/devel/gsettings-desktop-schemas


USE_XZ=		yes
USE_XORG=	x11 xext xrandr xcomposite xcursor xinerama ice sm xfixes \
		xrender xdamage
USE_PYTHON=	2.5+
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehier gnomeprefix gnomehack intlhack gtk30 ltverhack
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -fno-omit-frame-pointer
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-lexecinfo"
CONFIGURE_ARGS=	--enable-compile-warnings=maximum
GLIB_SCHEMAS=	org.gnome.mutter.gschema.xml

MAN1=		mutter-message.1 mutter-theme-viewer.1 \
		mutter-window-demo.1 mutter.1

PLIST_SUB=	VERSION=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e 's|-Wcast-align||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
