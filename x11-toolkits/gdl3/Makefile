# New ports collection makefile for:	gdl
# Date created:				24 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gdl3/Makefile,v 1.6 2011/02/24 11:56:10 kwm Exp $
#

PORTNAME=	gdl
PORTVERSION=	2.91.92
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Components intended to be shared between GNOME development tools

LATEST_LINK=	gdl3

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gtk30 intltool
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
