# New ports collection makefile for:	gnomepanel
# Date created:				27 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-panel3/Makefile,v 1.1 2010/07/26 12:42:30 kwm Exp $
#

PORTNAME=	gnome-panel
PORTVERSION=	2.31.4
PORTREVISION?=	0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Panel component for the GNOME 3 Desktop

USE_BZIP2=	yes

IGNORE=		Not supported yet

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	gweather.1:${PORTSDIR}/net/libgweather \
		canberra-gtk.0:${PORTSDIR}/audio/libcanberra \
		polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit

USE_GETTEXT=	yes
USE_XORG=	ice sm x11 xau xrandr
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop libwnck gnomemenus \
		gnomedocutils ltverhack referencehack
USE_GNOME+=	librsvg2
WANT_GNOME=	yes
# we can't use this yet. it still wants gnomedesktop gtk2 version
# when it depends on gnomedesktop3 also fix bsd.gnome.mk
#GNOME_DESKTOP_VERSION=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--disable-network-manager \
		--enable-polkit
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnome-panel.1
GCONF_SCHEMAS=	clock.schemas fish.schemas \
		panel-compatibility.schemas panel-general.schemas \
		panel-global.schemas panel-object.schemas \
		panel-toplevel.schemas window-list.schemas \
		workspace-switcher.schemas

OPTIONS=	EVOLUTION "use the Evolution calendar if installed" on \
		BONOBO "Support for bonobo applets aka Gnome 2 applets" on

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EVOLUTION) && ${HAVE_GNOME:Mevolutiondataserver3}!=""
USE_GNOME+=	evolutiondataserver3
CONFIGURE_ARGS+=--enable-eds
.else
CONFIGURE_ARGS+=--disable-eds
.endif

.if defined(WITH_BONOBO)
USE_GNOME+=	libbonoboui
CONFIGURE_ARGS+=--enable-bonobo
PLIST_SUB+=	BONOBO=""
.else
CONFIGURE_ARGS+=--disable-bonobo
PLIST_SUB+=	BONOBO="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|"applications.menu"|"gnome-applications.menu"|'
	@${REINPLACE_CMD} -e 's|xsltproc -o| xsltproc --nonet -o|g' \
		${WRKSRC}/help/clock/Makefile.in \
		${WRKSRC}/help/fish/Makefile.in
	@${REINPLACE_CMD} -e 's|libedataserverui-1.2|libedataserverui-3.0|g' \
		${WRKSRC}/configure
#		-e 's|gtk+-2.0|gtk+-3.0|g' \
#		-e 's|gnome-desktop-2.0|gnome-desktop-3.0|g' \

post-install:
	@${MKDIR} ${PREFIX}/lib/gnome-panel/modules
	-${LOCALBASE}/bin/gio-querymodules ${PREFIX}/lib/gnome-panel/modules

.include <bsd.port.post.mk>

.endif
