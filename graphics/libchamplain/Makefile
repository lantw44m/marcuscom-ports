# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/graphics/libchamplain/Makefile 17271 2013-04-01 15:16:27Z kwm $

PORTNAME=	libchamplain
PORTVERSION=	0.12.3
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C library aimed to provide a Gtk+ widget to display rasterized maps and markers

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	clutter-gtk-1.0:${PORTSDIR}/graphics/clutter-gtk3 \
		soup-gnome-2.4:${PORTSDIR}/devel/libsoup-gnome

USE_XZ=		yes
USES=		pathfix pkgconfig
USE_GNOME=	gtk30 ltverhack gnomehier
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_SQLITE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-gtk-doc-html=no

PLIST_SUB=	VERSION=0.12

post-patch:
	@${REINPLACE_CMD} -e 's|DOC_MODULE = libchamplain|DOC_MODULE = libchamplain-gtk3|g' \
		${WRKSRC}/docs/reference/Makefile.in \
		${WRKSRC}/docs/reference-gtk/Makefile.in

.include <bsd.port.mk>
