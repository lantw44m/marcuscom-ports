# New ports collection makefile for:	gdk-pixbuf
# Date created:		5th October 1999
# Whom:			Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#    $MCom: ports/graphics/gdk-pixbuf2/Makefile,v 1.21 2012/05/23 13:40:57 kwm Exp $

PORTNAME?=	gdk-pixbuf
PORTVERSION=	2.26.1
PORTREVISION=	1
CATEGORIES?=	graphics
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gdk-pixbuf/${PORTVERSION:R}
DISTNAME=	gdk-pixbuf-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A graphic library for GTK+

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

LATEST_LINK=	gdk-pixbuf2
USE_XZ=		yes
USE_GMAKE=	yes
USE_XORG=	xt xi x11
USE_AUTOTOOLS=	libtool
USE_GNOME+=	gnomehack glib20 ltverhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-introspection=yes --with-x11

MAN1=		gdk-pixbuf-csource.1 gdk-pixbuf-query-loaders.1

OPTIONS=	JP2 "JPEG2000 support"	ON \
		JPEG "JPEG support"	ON \
		PNG "PNG support"	ON \
		TIFF "TIFF support"	ON

.include <bsd.port.options.mk>

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_JP2)
LIB_DEPENDS+=	jasper:${PORTSDIR}/graphics/jasper
CONFIGURE_ARGS+=--with-libjasper
PLIST_SUB+=	JP2=""
.else
PLIST_SUB+=	JP2="@comment "
.endif

.if !defined(WITHOUT_JPEG)
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	JPEG=""
.else
CONFIGURE_ARGS+=--without-libjpeg
PLIST_SUB+=	JPEG="@comment "
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png:${PORTSDIR}/graphics/png
PLIST_SUB+=	PNG=""
.else
CONFIGURE_ARGS+=--without-libpng
PLIST_SUB+=	PNG="@comment "
.endif

.if !defined(WITHOUT_TIFF)
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
PLIST_SUB+=	TIFF=""
.else
CONFIGURE_ARGS+=--without-libtiff
PLIST_SUB+=	TIFF="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|" == "|" = "|g' ${WRKSRC}/configure

post-install:
	@cd ${WRKSRC}/docs/reference/gdk-pixbuf && gmake install-man1

.include <bsd.port.mk>
