# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	libsecret
PORTVERSION=	0.15
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to access the secret service API

LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt

USE_XZ=		yes
USE_GNOME=	gnomehier glib20 libxslt:build intltool
USE_GMAKE=	yes
USES=		gettext pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-introspection --disable-vala

MAN1=		secret-tool.1

.include <bsd.port.mk>
