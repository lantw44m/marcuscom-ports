# New ports collection makefile for:	libgdata
# Date created:				9 May 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libgdata/Makefile,v 1.19 2011/04/30 20:43:16 mezz Exp $
#

PORTNAME=	libgdata
PORTVERSION=	0.6.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GLib based implimentation of the GData protocol

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	soup-gnome-2.4.1:${PORTSDIR}/devel/libsoup-gnome

CONFLICTS=	libgdata-0.8.*

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack intltool ltverhack glib20
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include " \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--with-html-dir="${PREFIX}/share/doc"

.include <bsd.port.mk>
