# New ports collection makefile for:    librsvg2
# Date created:         		8th May 2001
# Whom:                 		Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD: ports/graphics/librsvg2/Makefile,v 1.40 2004/05/06 09:34:46 bland Exp $
#

PORTNAME=	librsvg2
PORTVERSION=	2.7.2
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/2.7
DISTNAME=	librsvg-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		popt.0:${PORTSDIR}/devel/popt \
		croco-${CROCO_VERSION}.3:${PORTSDIR}/textproc/libcroco
RUN_DEPENDS=	${X11BASE}/lib/gtk-2.0/${GTK_VERSION}/engines/libmetal.so:${PORTSDIR}/x11-themes/gtk-engines2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=13
USE_REINPLACE=	yes
USE_GNOME=	gnomehack gnomeprefix lthack libartlgpl2 libgsf gnomevfs2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-svgz \
		--disable-gtk-doc \
		--without-gimp \
		--enable-gnome-vfs \
		--with-croco

CROCO_VERSION=	0.6
GTK_VERSION=	2.4.0

PLIST_SUB=	GTK_VERSION=${GTK_VERSION}

MAN1=		rsvg.1

post-patch:
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
		${WRKSRC}/librsvg-2.0.pc.in

.include <bsd.port.mk>
