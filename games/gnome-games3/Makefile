# New ports collection makefile for:	gnomegames2
# Date created:				08 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/games/gnome-games3/Makefile,v 1.10 2011/04/21 09:25:35 kwm Exp $
#

PORTNAME=	gnome-games
PORTVERSION=	3.0.1.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The game applications package for the GNOME 3 Desktop Environment

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	guile.20:${PORTSDIR}/lang/guile \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3 \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		clutter-gtk-1.0.0:${PORTSDIR}/graphics/clutter-gtk3 \
		clutter-glx-1.0.0:${PORTSDIR}/graphics/clutter
#RUN_DEPENDS=	seed:${PORTSDIR}/devel/seed

CONFLICTS=	gnome-games-2.[0-9]*

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
GLIB_SCHEMAS=	org.gnome.Games.WindowState.gschema.xml
USE_GL=		gl glu
USE_XORG=	ice x11
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gtk30 gconf2 pygtk2 \
		librsvg2 desktopfileutils gnomedocutils 
USE_GSTREAMER=	vorbis ogg
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=3.0
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	aisleriot.schemas glines.schemas \
		gnect.schemas gnibbles.schemas gnobots2.schemas \
		gnomine.schemas gnotravex.schemas \
		gnotski.schemas gtali.schemas iagno.schemas \
		mahjongg.schemas lightsoff.schemas quadrapassel.schemas \
		swell-foop.schemas
GLIB_SCHEMAS=	org.gnome.Games.WindowState.gschema.xml \
		org.gnome.glchess.gschema.xml

CONFLICTS=	sol-1.0.* glchess-[0-9]* gnomesudoku-[0-9]*

MAN6=		glchess.6 glines.6 gnect.6 gnibbles.6 gnobots2.6 \
		gnomine.6 gnotravex.6 gnotski.6 \
		gtali.6 iagno.6 mahjongg.6 quadrapassel.6 sol.6

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
	    	${WRKSRC}/gnome-sudoku/src/lib/defaults.py.in

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
