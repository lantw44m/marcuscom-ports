# New ports collection makefile for:   at-spi
# Date Created:			12 April 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/at-spi2-core/Makefile,v 1.25 2011/03/23 11:06:43 kwm Exp $
#

PORTNAME=	at-spi2-core
PORTVERSION=	1.91.93
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An Assistive Technology Service Provider Interface

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus

LICENSE=        LGPL21
LICENSE_FILE=   ${WRKSRC}/COPYING
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomehier intlhack
USE_XORG=	x11 xi xtst
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
