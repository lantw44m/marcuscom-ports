# New ports collection makefile for:	mx
# Date created:		30 Mar 2011
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#  $MCom: ports/x11-toolkits/mx/Makefile,v 1.2 2011/04/13 18:13:15 kwm Exp $
#

PORTNAME=	mx
PORTVERSION=	1.2.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://source.clutter-project.org/sources/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter based widget toolkit

LICENSE=	LGPL21

LIB_DEPENDS=	clutter-glx-1.0.0:${PORTSDIR}/graphics/clutter \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack glib20 gtk20 intlhack ltverhack
USE_LDCONFIG=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
