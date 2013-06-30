# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#  $MCom$

PORTNAME=	mx
PORTVERSION=	1.2.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	LOCAL/kwm

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter based widget toolkit

LICENSE=	LGPL21

LIB_DEPENDS=	clutter-glx-1.0:${PORTSDIR}/graphics/clutter \
		startup-notification-1:${PORTSDIR}/x11/startup-notification \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib

USE_GMAKE=	yes
USES=		gettext pathfix
USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	glib20 gtk20 intlhack ltverhack
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
