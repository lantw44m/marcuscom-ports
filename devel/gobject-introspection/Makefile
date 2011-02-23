# New ports collection makefile for:	gobject-introspection
# Date created:				19 July 2009
# Whom:					Alexander Logvinov <avl@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/gobject-introspection/Makefile,v 1.31 2011/02/07 21:58:12 kwm Exp $
#

PORTNAME=	gobject-introspection
PORTVERSION=	0.10.3
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Generate interface introspection data for GObject libraries

BUILD_DEPENDS=	flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	ffi.5:${PORTSDIR}/devel/libffi \
		cairo.2:${PORTSDIR}/graphics/cairo

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 ltverhack
USE_PYTHON=	yes
USE_BISON=	both
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-tests

# Force it to put the .cache in ${WRKSRC} instead of ~/.cache. ports/143260
MAKE_ENV=	HOME=${WRKDIR}

MAN1=		g-ir-compiler.1 g-ir-generate.1 g-ir-scanner.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|'cc'|'${CC:Q}'|g' \
		${WRKSRC}/giscanner/sourcescanner.py

.include <bsd.port.post.mk>

