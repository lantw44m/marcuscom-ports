# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/www/libepc/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTNAME=	libepc
PORTVERSION=	0.4.4
CATEGORIES=	www
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	The Easy Publish and Consume library

LIB_DEPENDS=	uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		soup-2.4:${PORTSDIR}/devel/libsoup \
		gnutls:${PORTSDIR}/security/gnutls \
		avahi-ui-gtk3:${PORTSDIR}/net/avahi-gtk3

USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	gnomeprefix gtk30
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
