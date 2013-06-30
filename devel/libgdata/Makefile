# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	libgdata
PORTVERSION=	0.12.0
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GLib based implimentation of the GData protocol

BUILD_DEPENDS=	ca_root_nss>=0:${PORTSDIR}/security/ca_root_nss
LIB_DEPENDS=	soup-gnome-2.4:${PORTSDIR}/devel/libsoup-gnome \
		oauth:${PORTSDIR}/net/liboauth
RUN_DEPENDS=	ca_root_nss>=0:${PORTSDIR}/security/ca_root_nss

CONFLICTS=	libgdata-0.6.*

USE_XZ=		yes
USE_LDCONFIG=	yes
USES=		gettext pathfix pkgconfig
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix intltool ltverhack glib20 introspection:build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-ca-certs=${LOCALBASE}/share/certs/ca-root-nss.crt

.include <bsd.port.mk>
