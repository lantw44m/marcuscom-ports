# New ports collection makefile for:   libchamplain
# Date Created:			04 Aug 2009
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/libchamplain/Makefile,v 1.29 2011/09/18 15:11:01 kwm Exp $
#

PORTNAME=	libchamplain
PORTVERSION=	0.12.1
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A C library aimed to provide a Gtk+ widget to display rasterized maps and markers

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		clutter-gtk-1.0.0:${PORTSDIR}/graphics/clutter-gtk3 \
		soup-gnome-2.4.1:${PORTSDIR}/devel/libsoup-gnome

USE_XZ=		yes
USE_GNOME=	pkgconfig gtk30 gnomehack ltverhack gnomehier
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-gtk-doc-html=no

PLIST_SUB=	VERSION=0.12

post-patch:
	@${REINPLACE_CMD} -e 's|DOC_MODULE = libchamplain|DOC_MODULE = libchamplain-gtk3|g' \
		${WRKSRC}/docs/reference/Makefile.in \
		${WRKSRC}/docs/reference-gtk/Makefile.in

.include <bsd.port.mk>
