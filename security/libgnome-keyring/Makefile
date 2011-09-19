# New ports collection makefile for:	libgnome-keyring
# Date created:		2009-12-21
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/security/libgnome-keyring/Makefile,v 1.19 2011/09/16 19:41:10 kwm Exp $
#

PORTNAME=	libgnome-keyring
PORTVERSION=	3.1.92
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A program that keeps passwords and other secrets

LIB_DEPENDS=    dbus-1.3:${PORTSDIR}/devel/dbus \
                gcrypt.18:${PORTSDIR}/security/libgcrypt

USE_XZ=		yes
USE_GNOME=	gnomehack gnomeprefix ltverhack intlhack glib20
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
