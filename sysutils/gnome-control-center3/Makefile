# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/gnome-control-center3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	gnome-control-center
PORTVERSION=	3.6.3
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for GNOME 3 project

BUILD_DEPENDS=	gnome-settings-daemon>=3.4.0:${PORTSDIR}/sysutils/gnome-settings-daemon3 \
		gsettings-desktop-schemas>=3.2.2:${PORTSDIR}/devel/gsettings-desktop-schemas \
		libpwquality>=0:${PORTSDIR}/security/libpwquality \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	canberra-gtk3:${PORTSDIR}/audio/libcanberra-gtk3 \
		xklavier:${PORTSDIR}/x11/libxklavier \
		upower-glib:${PORTSDIR}/sysutils/upower \
		colord:${PORTSDIR}/graphics/colord \
		ibus:${PORTSDIR}/textproc/ibus \
		goa-1.0:${PORTSDIR}/net/gnome-online-accounts \
		socialweb:${PORTSDIR}/www/libsocialweb \
		gtop-2.0:${PORTSDIR}/devel/libgtop \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		polkit-gobject-1:${PORTSDIR}/sysutils/polkit
RUN_DEPENDS=	gnome-eject:${PORTSDIR}/sysutils/gnome-mount \
		gnome-settings-daemon>=3.4.0:${PORTSDIR}/sysutils/gnome-settings-daemon3 \
		gsettings-desktop-schemas>=3.2.2:${PORTSDIR}/devel/gsettings-desktop-schemas \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		glxinfo:${PORTSDIR}/graphics/mesa-demos \
		apg:${PORTSDIR}/security/apg \
		gcm-calibrate:${PORTSDIR}/graphics/gnome-color-manager

CONFLICTS=	gnome-control-center-2.[0-9]* gnome-media-2.[0-9]*

LATEST_LINK=	gnome-control-center3
USE_XZ=		yes
USES=		desktop-file-utils gettext pathfix pkgconfig shared-mime-info
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehier intlhack libxml2 gnomemenus3 \
		libgnomekbd3 gnomedesktop3 gconf2
USE_XORG=	xscrnsaver x11 xxf86misc kbproto xi
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-libsocialweb=yes --disable-systemd
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gnome-control-center.1

OPTIONS_DEFINE=	CUPS
OPTIONS_DEFAULT=CUPS
CUPS_DESC=	Cups (printing) support
CHEESE_DESC=	Cheese webcam support

OPTIONS_DEFINE_i386=	CHEESE
OPTIONS_DEFAULT_i386=	CHEESE
OPTIONS_DEFINE_amd64=	CHEESE
OPTIONS_DEFAULT_amd64=	CHEESE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
LIB_DEPENDS+=	cups:${PORTSDIR}/print/cups-client
PLIST_SUB+=	CUPS=""
.else
PLIST_SUB+=	CUPS="@comment "
CONFIGURE_ARGS+=--disable-cups
.endif

.if ${PORT_OPTIONS:MCHEESE}
CONFIGURE_ARGS+=--with-cheese
BUILD_DEPENDS+=	cheese>=3.0.1:${PORTSDIR}/multimedia/cheese3
LIB_DEPENDS+=	cheese:${PORTSDIR}/multimedia/cheese3
.else
CONFIGURE_ARGS+=--without-cheese
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|datetime wacom|datetime|g' \
		${WRKSRC}/panels/Makefile.in

.include <bsd.port.mk>
