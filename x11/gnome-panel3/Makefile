# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/gnome-panel3/Makefile 18392 2013-04-26 11:23:16Z mezz $

PORTNAME=	gnome-panel
PORTVERSION=	3.4.2.1
PORTREVISION?=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Panel component for the GNOME 3 Desktop

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	gweather-3.0:${PORTSDIR}/net/libgweather3 \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib \
		canberra-gtk3:${PORTSDIR}/audio/libcanberra-gtk3 \
		polkit-gobject-1:${PORTSDIR}/sysutils/polkit
RUN_DEPENDS=	${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon

CONFLICTS=	gnome-panel-2.[0-9]*

LATEST_LINK=	gnome-panel3
USES=		gettext pathfix pkgconfig
USE_XORG=	ice sm x11 xau xrandr
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intlhack gnomedesktop3 librsvg2 libwnck3 \
		gnomemenus3 gnomedocutils ltverhack referencehack
WANT_GNOME=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-network-manager
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gnome-panel.1
GCONF_SCHEMAS=	clock.schemas
GLIB_SCHEMAS=	org.gnome.gnome-panel.applet.fish.gschema.xml \
		org.gnome.gnome-panel.applet.window-list.gschema.xml \
		org.gnome.gnome-panel.applet.workspace-switcher.gschema.xml \
		org.gnome.gnome-panel.enums.xml \
		org.gnome.gnome-panel.gschema.xml \
		org.gnome.gnome-panel.launcher.gschema.xml \
		org.gnome.gnome-panel.menu-button.gschema.xml \
		org.gnome.gnome-panel.object.gschema.xml \
		org.gnome.gnome-panel.toplevel.gschema.xml

#OPTIONS=	EVOLUTION "use the Evolution calendar if installed" on

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

#.if !defined(WITHOUT_EVOLUTION) && ${HAVE_GNOME:Mevolutiondataserver3}!=""
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

.include <bsd.port.post.mk>

.endif
