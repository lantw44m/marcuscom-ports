# New ports collection makefile for:	gnomebackgrounds
# Date created:				12 January 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomebackgrounds
PORTVERSION=	2.9.4
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-backgrounds/2.9
DISTNAME=	gnome-backgrounds-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of backgrounds for the GNOME Desktop

USE_BZIP2=	yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
