# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/libgnome-keyring/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libgnome-keyring
PORTVERSION=	3.6.0
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A program that keeps passwords and other secrets

LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		gcrypt:${PORTSDIR}/security/libgcrypt

USE_XZ=		yes
USE_GNOME=	glib20 gnomehier gnomeprefix intlhack \
		introspection:build ltverhack
USES=		gettext gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
