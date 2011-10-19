# New ports collection makefile for:	gnomegames2
# Date created:				08 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/games/gnome-games3/Makefile,v 1.17 2011/10/15 19:17:42 kwm Exp $
#

PORTNAME=	gnome-games
PORTVERSION=	3.2.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The game applications package for the GNOME 3 Desktop Environment

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	guile.21:${PORTSDIR}/lang/guile \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		canberra-gtk3.0:${PORTSDIR}/audio/libcanberra-gtk3 \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		clutter-gtk-1.0.0:${PORTSDIR}/graphics/clutter-gtk3 \
		clutter-glx-1.0.0:${PORTSDIR}/graphics/clutter

CONFLICTS=	sol-1.0.* glchess-[0-9]* gnomesudoku-[0-9]* gnome-games-2.[0-9]*

LATEST_LINK=	gnome-games3
USE_XZ=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GL=		gl glu
USE_XORG=	ice x11
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gtk30 gconf2 pygobject3 \
		librsvg2 desktopfileutils gnomedocutils
USE_GSTREAMER=	vorbis ogg
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=3.0 --enable-games=all
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gnect.schemas gnibbles.schemas gnobots2.schemas \
		gnome-sudoku.schemas \
		gnotski.schemas gtali.schemas \
		quadrapassel.schemas
GLIB_SCHEMAS=	org.gnome.Games.WindowState.gschema.xml \
		org.gnome.glchess.gschema.xml \
		org.gnome.glines.gschema.xml \
		org.gnome.gnomine.gschema.xml \
		org.gnome.gnotravex.gschema.xml \
		org.gnome.iagno.gschema.xml \
		org.gnome.mahjongg.gschema.xml

MAN6=		glchess.6 glines.6 gnect.6 gnibbles.6 gnobots2.6 \
		gnome-sudoku.6 gnomine.6 gnotravex.6 gnotski.6 \
		gtali.6 iagno.6 mahjongg.6 quadrapassel.6

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
