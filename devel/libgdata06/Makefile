# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libgdata06/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	libgdata
PORTVERSION=	0.6.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GLib based implimentation of the GData protocol

LIB_DEPENDS=	soup-gnome-2.4:${PORTSDIR}/devel/libsoup-gnome

CONFLICTS=	libgdata-0.10.*

LATEST_LINK=	libgdata06
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=		gettext pathfix pkgconfig
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	intltool ltverhack glib20 introspection:build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-html-dir="${PREFIX}/share/doc"

.include <bsd.port.mk>
