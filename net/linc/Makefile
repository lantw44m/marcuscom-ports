# New ports collection makefile for:   linc
# Date Created:			12 February 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD: ports/net/linc/Makefile,v 1.26 2003/03/07 06:07:50 ade Exp $
#

PORTNAME=	linc
PORTVERSION=	1.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.1
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A library for writing networked servers & clients

LIB_DEPENDS=	glib-2.0.200:${PORTSDIR}/devel/glib20

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
