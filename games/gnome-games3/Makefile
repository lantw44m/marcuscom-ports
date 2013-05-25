# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/games/gnome-games3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	gnome-games
PORTVERSION=	3.4.2
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The game applications package for the GNOME 3 Desktop Environment

BUILD_DEPENDS=	yelp-tools>=0:${PORTSDIR}/textproc/yelp-tools \
		itstool:${PORTSDIR}/textproc/itstool \
		valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	guile:${PORTSDIR}/lang/guile \
		canberra-gtk3:${PORTSDIR}/audio/libcanberra-gtk3 \
		clutter-gtk-1.0:${PORTSDIR}/graphics/clutter-gtk3 \
		clutter-1.0:${PORTSDIR}/graphics/clutter
RUN_DEPENDS=	dbus-launch:${PORTSDIR}/devel/dbus

CONFLICTS=	sol-1.0.* glchess-[0-9]* gnomesudoku-[0-9]* gnome-games-2.[0-9]*

LATEST_LINK=	gnome-games3
USE_XZ=		yes
USE_PYTHON=	yes
USES=		gettext pathfix desktop-file-utils pkgconfig
INSTALLS_ICONS=	yes
USE_GL=		gl glu
USE_XORG=	ice x11
USE_GMAKE=	yes
USE_SQLITE=	yes
USE_GNOME=	gnomeprefix intlhack gtk30 pygobject3 librsvg2 \
		introspection:build
USE_GSTREAMER=	vorbis ogg
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=3.0 --enable-games=all
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.Games.WindowState.gschema.xml \
		org.gnome.glchess.gschema.xml \
		org.gnome.glines.gschema.xml \
		org.gnome.gnect.gschema.xml \
		org.gnome.gnibbles.gschema.xml \
		org.gnome.gnobots2.gschema.xml \
		org.gnome.gnome-sudoku.gschema.xml \
		org.gnome.gnomine.gschema.xml \
		org.gnome.gnotravex.gschema.xml \
		org.gnome.gnotski.gschema.xml \
		org.gnome.gtali.gschema.xml \
		org.gnome.iagno.gschema.xml \
		org.gnome.lightsoff.gschema.xml \
		org.gnome.mahjongg.gschema.xml \
		org.gnome.quadrapassel.gschema.xml \
		org.gnome.swell-foop.gschema.xml

MAN6=		glchess.6 glines.6 gnect.6 gnibbles.6 gnobots2.6 \
		gnome-sudoku.6 gnomine.6 gnotravex.6 gnotski.6 \
		gtali.6 iagno.6 mahjongg.6 quadrapassel.6

post-install:
	${CHGRP} games ${LOCALBASE}/share/games
	${CHMOD} g=rwXs ${LOCALBASE}/share/games

.include <bsd.port.mk>
