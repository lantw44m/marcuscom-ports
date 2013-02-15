# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/security/libgnome-keyring/Makefile,v 1.24 2012/05/26 10:39:01 kwm Exp $

PORTNAME=	libgnome-keyring
PORTVERSION=	3.4.1
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A program that keeps passwords and other secrets

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		gcrypt:${PORTSDIR}/security/libgcrypt

USE_XZ=		yes
USE_GNOME=	gnomehier gnomehack gnomeprefix ltverhack intlhack glib20
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
