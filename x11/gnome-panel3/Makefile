# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/gnome-panel3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gnome-panel
PORTVERSION=	3.6.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Panel component for the GNOME 3 Desktop

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	gweather-3:${PORTSDIR}/net/libgweather3 \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib \
		canberra-gtk3:${PORTSDIR}/audio/libcanberra-gtk3 \
		polkit-gobject-1:${PORTSDIR}/sysutils/polkit
RUN_DEPENDS=	${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon

CONFLICTS=	gnome-panel-2.[0-9]*

LATEST_LINK=	gnome-panel3
USES=		gettext gmake pathfix pkgconfig
USE_XORG=	ice sm x11 xau xrandr
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intlhack gnomedesktop3 librsvg2 libwnck3 \
		gnomemenus3 ltverhack referencehack
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-network-manager
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gnome-panel.1
GLIB_SCHEMAS=	org.gnome.gnome-panel.applet.clock.gschema.xml \
		org.gnome.gnome-panel.applet.fish.gschema.xml \
		org.gnome.gnome-panel.applet.window-list.gschema.xml \
		org.gnome.gnome-panel.applet.workspace-switcher.gschema.xml \
		org.gnome.gnome-panel.enums.xml \
		org.gnome.gnome-panel.gschema.xml \
		org.gnome.gnome-panel.launcher.gschema.xml \
		org.gnome.gnome-panel.menu-button.gschema.xml \
		org.gnome.gnome-panel.object.gschema.xml \
		org.gnome.gnome-panel.toplevel.gschema.xml

#OPTIONS_DEFINE=	EVOLUTION
#OPTIONS_DEFAULT=EVOLUTION
#EVOLUTION_DESC=	Evolution calendar support

.include <bsd.port.options.mk>

#.if ${PORT_OPTIONS:MEVOLUTION}
#USE_GNOME+=	evolutiondataserver3
#CONFIGURE_ARGS+=--enable-eds
#.else
CONFIGURE_ARGS+=--disable-eds
#.endif

post-patch:
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|"applications.menu"|"gnome-applications.menu"|'
	@${REINPLACE_CMD} -e 's|xsltproc -o| xsltproc --nonet -o|g' \
		${WRKSRC}/help/clock/Makefile.in \
		${WRKSRC}/help/fish/Makefile.in

.include <bsd.port.mk>

.endif
