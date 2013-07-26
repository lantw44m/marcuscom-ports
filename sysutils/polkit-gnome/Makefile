# Created by: Koop Mast<kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/polkit-gnome/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	polkit-gnome
PORTVERSION=	0.102
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME frontend to the PolicyKit framework

LIB_DEPENDS=	polkit-gobject-1:${PORTSDIR}/sysutils/polkit

USE_XZ=		yes
USES=		gettext gmake pathfix
USE_GNOME=	gnomeprefix gtk20 intlhack introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-gtk=2.0 \
		--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
