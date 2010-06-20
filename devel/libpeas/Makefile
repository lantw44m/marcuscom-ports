# New ports collection makefile for:	libpeas
# Date created:				20 June 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	libpeas
PORTVERSION=	0.5.0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Next evolution of the Gedit plugins engine

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		pygobject-codegen-2.0:${PORTSDIR}/devel/py-gobject
LIB_DEPENDS=	seed.0:${PORTSDIR}/devel/seed
RUN_DEPENDS=	pygobject-codegen-2.0:${PORTSDIR}/devel/py-gobject

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack glib20 gtk30 ltverhack:0
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include " \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
