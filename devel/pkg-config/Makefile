# New ports collection makefile for:	pkgconfig
# Date created:				30 April 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD: ports/devel/pkgconfig/Makefile,v 1.25 2002/11/04 18:54:18 marcus Exp $
#

PORTNAME=	pkgconfig
PORTVERSION=	0.14.0
CATEGORIES=	devel
MASTER_SITES=	http://www.freedesktop.org/software/pkgconfig/releases/ \
		${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.14
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

#USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	glib-1.2.8/configure
LIBTOOLFLAGS=	--disable-ltlibs \
		--disable-shared
CONFIGURE_ARGS=	--disable-threads
MAKE_ENV=	PKGCONF_BUILD=yes

PLIST_SUB=	LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

MAN1=		pkg-config.1

post-install:
	${MKDIR} ${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
