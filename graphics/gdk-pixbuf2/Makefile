# New ports collection makefile for:	gdk-pixbuf
# Date created:		5th October 1999
# Whom:			Ade Lovett <ade@lovett.com>
#
# $FreeBSD$
#    $MCom: ports/graphics/gdk-pixbuf2/Makefile,v 1.3 2010/06/29 21:14:00 kwm Exp $

PORTNAME?=	gdk-pixbuf
PORTVERSION=	2.21.6
CATEGORIES?=	graphics
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gdk-pixbuf/${PORTVERSION:R}
DISTNAME=	gdk-pixbuf-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A graphic library for GTK+

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.11:${PORTSDIR}/graphics/jpeg

LATEST_LINK=	gdk-pixbuf2
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	xt xi x11
USE_AUTOTOOLS=	libtool:22
USE_GNOME+=	gnomehack glib20 ltverhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gdk-pixbuf-csource.1 gdk-pixbuf-query-loaders.1

post-install:
	@cd ${WRKSRC}/docs/reference/gdk-pixbuf && gmake install-man1

.include <bsd.port.mk>
