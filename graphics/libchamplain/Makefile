# New ports collection makefile for:   libchamplain
# Date Created:			04 Aug 2009
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/libchamplain/Makefile,v 1.1 2009/08/08 17:02:47 kwm Exp $
#

PORTNAME=	libchamplain
PORTVERSION=	0.3.90
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A C library aimed to provide a Gtk+ widget to display rasterized maps and markers

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		clutter-gtk-0.10.0:${PORTSDIR}/graphics/clutter-gtk \
		soup-gnome-2.4.1:${PORTSDIR}/devel/libsoup

USE_BZIP2=	yes
USE_GNOME=	pkgconfig gtk20 gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-introspection=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

# python bindings and mono need to be ported to clutter 1.0 first.
# And clutter 1.0 versions of py-clutter and clutter-sharp need to 
# get released upstream too.
CONFIGURE_ARGS+=--enable-python=no --enable-managed=no

#python
# py-gtk py-gobject, glib20 clutter-0.8 py-clutter-0.8 gconf gtk20

# mono
# mono, gtk-sharp20 clutter-sharp

.include <bsd.port.mk>
