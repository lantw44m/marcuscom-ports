# New ports collection makefile for:	gnomepanel
# Date created:				27 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-panel3/Makefile,v 1.20 2011/06/10 22:59:10 mezz Exp $
#

PORTNAME=	gnome-panel
PORTVERSION=	3.1.91
PORTREVISION?=	0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Panel component for the GNOME 3 Desktop

USE_XZ=		yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	gweather-3.0:${PORTSDIR}/net/libgweather3 \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib \
		canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3 \
		polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit
RUN_DEPENDS=	${LOCALBASE}/libexec/notification-daemon:${PORTSDIR}/deskutils/notification-daemon

CONFLICTS=	gnome-panel-2.[0-9]*

LATEST_LINK=	gnome-panel3
USE_GETTEXT=	yes
USE_XORG=	ice sm x11 xau xrandr
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop3 librsvg2 libwnck3 \
		gnomemenus3 gnomedocutils ltverhack referencehack
WANT_GNOME=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-network-manager
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

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

#OPTIONS=	EVOLUTION "use the Evolution calendar if installed" on \
#		BONOBO "Support for bonobo applets aka Gnome 2 applets" on

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

#.if defined(WITH_BONOBO)
#USE_GNOME+=	libbonoboui
#CONFIGURE_ARGS+=--enable-bonobo
#PLIST_SUB+=	BONOBO=""
#.else
#CONFIGURE_ARGS+=--disable-bonobo
PLIST_SUB+=	BONOBO="@comment "
#.endif

post-patch:
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|"applications.menu"|"gnome-applications.menu"|'
	@${REINPLACE_CMD} -e 's|xsltproc -o| xsltproc --nonet -o|g' \
		${WRKSRC}/help/clock/Makefile.in \
		${WRKSRC}/help/fish/Makefile.in

post-install:
	@${MKDIR} ${PREFIX}/lib/gnome-panel/modules
	-${LOCALBASE}/bin/gio-querymodules ${PREFIX}/lib/gnome-panel/modules

.include <bsd.port.post.mk>

.endif
