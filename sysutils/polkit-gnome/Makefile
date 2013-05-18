# Created by: Koop Mast<kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/polkit-gnome/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	polkit-gnome
PORTVERSION=	0.102
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME frontend to the PolicyKit framework

LIB_DEPENDS=	polkit-gobject-1:${PORTSDIR}/sysutils/polkit

USE_XZ=		yes
USE_GMAKE=	yes
USES=		gettext pathfix
USE_GNOME=	gnomeprefix gtk20 intlhack introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-gtk=2.0 \
		--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
