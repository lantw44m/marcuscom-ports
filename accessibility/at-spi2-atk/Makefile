# New ports collection makefile for:   at-spi
# Date Created:			12 April 2002
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/at-spi2-atk/Makefile,v 1.20 2011/03/03 10:45:25 kwm Exp $
#

PORTNAME=	at-spi2-atk
PORTVERSION=	1.91.91
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Assisted Technology Provider module for GTK+

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	${LOCALBASE}/libexec/at-spi2-registryd:${PORTSDIR}/accessibility/at-spi2-core

LICENSE=        LGPL21
LICENSE_FILE=   ${WRKSRC}/COPYING
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomehier intlhack gconf2 libxml2
GNOME_DESKTOP_VERSION=3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
GLIB_SCHEMAS=	org.a11y.atspi.gschema.xml

.include <bsd.port.mk>
