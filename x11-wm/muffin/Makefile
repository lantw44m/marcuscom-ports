# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	muffin
PORTVERSION=	1.7.1
CATEGORIES=	x11-wm gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	Compositing window manager forked from Mutter for use with Cinnamon

BUILD_DEPENDS=	zenity>3.0.0:${PORTSDIR}/x11/zenity3 \
		gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		gsettings-desktop-schemas>=3.4.0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libclutter-glx-1.so:${PORTSDIR}/graphics/clutter \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3
RUN_DEPENDS=	zenity>=3.0.0:${PORTSDIR}/x11/zenity3

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
GH_TAGNAME=	1.7.1
GH_COMMIT=	4b36a9a

NO_STAGE=	yes
USE_XORG=	x11 xext xrandr xcomposite xcursor xinerama ice sm
USE_PYTHON=	2.5+
USES=		gettext gmake pathfix
USE_AUTOTOOLS=	libtool autoconf automake
USE_GNOME=	gnomehier gnomeprefix intlhack gtk30 gconf2 introspection:build
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-lexecinfo"
CONFIGURE_ARGS=	--enable-compile-warnings=maximum
GLIB_SCHEMAS=	org.cinnamon.muffin.gschema.xml

MAN1=		muffin-message.1 muffin-theme-viewer.1 muffin-window-demo.1 \
		muffin.1

pre-configure:
		@cd ${WRKSRC} && ${SH} autogen.sh

.include <bsd.port.mk>
