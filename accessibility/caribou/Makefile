# New ports collection makefile for:   caribou
# Date created:			10 Juni 2010
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$
#

PORTNAME=	caribou
PORTVERSION=	0.1.2
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome On-Screen keyboard

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pyclutter-1.0.pc:${PORTSDIR}/graphics/py-clutter
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pyclutter-1.0.pc:${PORTSDIR}/graphics/py-clutter

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PYTHON=	yes
#USE_GNOME=	gnomeprefix gnomehack gtk20
USE_GNOME=	intltool pygtk2
#USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
#CONFIGURE_ARGS=	--enable-static

.include <bsd.port.mk>
