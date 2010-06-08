# New ports collection makefile for:	gnomegames2
# Date created:				08 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/games/gnome-games/Makefile,v 1.221 2010/05/29 17:23:49 kwm Exp $
#

PORTNAME=	gnome-games
PORTVERSION=	2.31.3
PORTREVISION=	0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The game applications package for the GNOME 2 Desktop Environment

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	guile.20:${PORTSDIR}/lang/guile \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		clutter-gtk-0.10.0:${PORTSDIR}/graphics/clutter-gtk \
		clutter-glx-1.0.0:${PORTSDIR}/graphics/clutter
RUN_DEPENDS=	seed:${PORTSDIR}/devel/seed

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
GLIB_SCHEMAS=	org.gnome.Games.WindowState.gschema.xml
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2 pygtk2 \
		librsvg2 desktopfileutils gnomedocutils
USE_GSTREAMER=	vorbis ogg
GNU_CONFIGURE=	yes
# temporarly disable, seems GSettings is missing from glib gir. (or I'm missing something)
CONFIGURE_ARGS=--enable-introspection=no 
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	aisleriot.schemas glchess.schemas glines.schemas \
		gnect.schemas gnibbles.schemas gnobots2.schemas \
		gnome-sudoku.schemas gnomine.schemas gnotravex.schemas \
		gnotski.schemas gtali.schemas iagno.schemas lightsoff.schemas \
		mahjongg.schemas quadrapassel.schemas swell-foop.schemas

CONFLICTS=	sol-1.0.* glchess-[0-9]* gnomesudoku-[0-9]*

MAN6=		glchess.6 glines.6 gnect.6 gnibbles.6 gnobots2.6 \
		gnome-sudoku.6 gnomine.6 gnotravex.6 gnotski.6 \
		gtali.6 iagno.6 mahjongg.6 quadrapassel.6 sol.6

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libavahi-client.a) || defined(WITH_MDNS)
LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi-app
.endif

post-patch:
#	workaround for configure bug, should be fixed in 2.31.3.
	@${REINPLACE_CMD} -e 's|as_fn_error "couldn|as_fn_warning "couldn|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
	    	${WRKSRC}/gnome-sudoku/src/lib/defaults.py.in \
		${WRKSRC}/glchess/src/lib/defaults.py.in

pre-install:
	@cd ${WRKSRC}/libgames-support && gmake org.gnome.Games.WindowState.gschema.xml
	@${INSTALL_DATA} ${WRKSRC}/libgames-support/org.gnome.Games.WindowState.gschema.xml \
		${PREFIX}/share/glib-2.0/schemas/

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
