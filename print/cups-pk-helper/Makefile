# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	cups-pk-helper
PORTVERSION=	0.2.0
CATEGORIES=	print
MASTER_SITES=	http://www.freedesktop.org/software/${PORTNAME}/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A helper that makes system-config-printer use PolicyKit

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		cups:${PORTSDIR}/print/cups-client \
		polkit-gobject-1:${PORTSDIR}/sysutils/polkit

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	intlhack glib20
USES=		gettext pathfix pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/libs

.include <bsd.port.mk>
