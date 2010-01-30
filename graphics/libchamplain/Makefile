# New ports collection makefile for:   libchamplain
# Date Created:			04 Aug 2009
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/libchamplain/Makefile,v 1.14 2010/01/11 05:21:56 marcus Exp $
#

PORTNAME=	libchamplain
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A C library aimed to provide a Gtk+ widget to display rasterized maps and markers

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		clutter-gtk-0.10.0:${PORTSDIR}/graphics/clutter-gtk \
		soup-gnome-2.4.1:${PORTSDIR}/devel/libsoup

USE_BZIP2=	yes
USE_GNOME=	pkgconfig gtk20 gnomehack ltverhack:1
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

# python bindings and mono need to be ported to clutter 1.0 first.
# And clutter 1.0 versions of py-clutter and clutter-sharp need to
# get released upstream too.
CONFIGURE_ARGS+=--enable-managed=no

PLIST_SUB=	VERSION=${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	yes
PYCLUTTER_GTK=		${LOCALBASE}/libdata/pkgconfig/pyclutter-gtk-0.9.pc
BUILD_DEPENDS+=		${PYCLUTTER_GTK}:${PORTSDIR}/graphics/py-clutter-gtk
RUN_DEPENDS+=		${PYCLUTTER_GTK}:${PORTSDIR}/graphics/py-clutter-gtk
CONFIGURE_ARGS+=	--enable-python=yes
PLIST_SUB+=		PYTHON=""
.else
CONFIGURE_ARGS+=	--enable-python=no
PLIST_SUB+=		PYTHON="@comment "
.endif

.pre-everything:
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Specify WITHOUT_PYTHON=yes to disable python bindings"
	@${ECHO_CMD} ""

.include <bsd.port.mk>
