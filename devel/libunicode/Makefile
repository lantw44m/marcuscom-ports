# New ports collection makefile for:	libunicode
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTNAME=	libunicode
PORTVERSION=	0.4
PORTREVISION=	6
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/libunicode/0.4
DISTNAME=	${PORTNAME}-${PORTVERSION}.gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A library for manipulating Unicode characters and strings

USE_GMAKE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
