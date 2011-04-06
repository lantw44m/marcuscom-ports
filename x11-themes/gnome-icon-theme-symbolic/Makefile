# New ports collection makefile for:	gnome-icon-theme-symbolic
# Date Created:				16 March 2011
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-themes/gnome-icon-theme-symbolic/Makefile,v 1.5 2011/03/29 20:37:12 kwm Exp $
#

PORTNAME=	gnome-icon-theme-symbolic
PORTVERSION=	3.0.0
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME Symbolic Icons

BUILD_DEPENDS=	icon-naming-utils>=0.8.7:${PORTSDIR}/x11-themes/icon-naming-utils

USE_BZIP2=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
