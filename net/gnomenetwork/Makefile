# New ports collection makefile for:   gnomenetwork
# Date Created:			03 June 2003
# Whom:				Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomenetwork
PORTVERSION=	1.99.1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-network/1.99
DISTNAME=	gnome-network-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A library for writing networked servers & clients

IGNORE=		"This port is in bad need of a good de-Linuxing"

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
