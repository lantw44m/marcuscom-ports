# New ports collection makefile for:   metacity
# Date created:        21 May 2002
# Whom:                Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD: ports/x11-wm/metacity/Makefile,v 1.24 2004/02/04 05:10:22 marcus Exp $
#

PORTNAME=	metacity
PORTVERSION=	2.7.0
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.7
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A window manager for the adult in you

LIB_DEPENDS=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack lthack gnomehier gconf2 libglade2
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

.include <bsd.port.mk>
