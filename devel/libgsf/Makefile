# New ports collection makefile for:	libgsf
# Date created:				11 September 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libgsf/Makefile,v 1.11 2005/06/28 05:40:02 adamw Exp $
#

PORTNAME=	libgsf
PORTVERSION=	1.12.1
CATEGORIES?=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	An extensible i/o abstraction for dealing with structured file formats

.if !exists(/usr/lib/libbz2.so.1)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME?=	gnomehack glib20 libxml2
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc --without-gnome --with-bz2
CONFIGURE_ENV?=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
