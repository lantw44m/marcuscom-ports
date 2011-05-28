# New ports collection makefile for:	gnomecontrolcenter2
# Date created:				04 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-control-center3/Makefile,v 1.22 2011/04/27 21:43:43 kwm Exp $
#

PORTNAME=	gnome-control-center
PORTVERSION=	3.0.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for GNOME 3 project

BUILD_DEPENDS=	gnome-settings-daemon>=2.91.0:${PORTSDIR}/sysutils/gnome-settings-daemon3 \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3 \
		xklavier.12:${PORTSDIR}/x11/libxklavier \
		upower-glib.1:${PORTSDIR}/sysutils/upower \
		gtop-2.0.7:${PORTSDIR}/devel/libgtop \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit
RUN_DEPENDS=	gnome-eject:${PORTSDIR}/sysutils/gnome-mount \
		gnome-settings-daemon>=2.91.0:${PORTSDIR}/sysutils/gnome-settings-daemon3 \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		glxinfo:${PORTSDIR}/graphics/mesa-demos

CONFLICTS=	gnome-control-center-2.[0-9]* gnome-media-2.[0-9]*

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier intlhack libxml2 gnomemenus \
		libgnomekbd3 desktopfileutils gnomedesktop3 gconf2
USE_XORG=	xscrnsaver x11 xxf86misc kbproto
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-libsocialweb=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

OPTIONS=	CUPS "Enable cups (printing) support" On \
		CHEESE "Enable cheese webcam support" Off

.include <bsd.port.pre.mk>

.if defined(WITH_CUPS)
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-client
PLIST_SUB+=	CUPS=""
.else
PLIST_SUB+=	CUPS="@comment "
CONFIGURE_ARGS+=--disable-cups
.endif

.if defined(WITH_CHEESE) && (${ARCH}=="i386" || ${ARCH}=="amd64")
CONFIGURE_ARGS+=--with-cheese
BUILD_DEPENDS+=	cheese>=3.0.1:${PORTSDIR}/multimedia/cheese3
LIB_DEPENDS+=	cheese.1:${PORTSDIR}/multimedia/cheese3
.else
CONFIGURE_ARGS+=--without-cheese
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
