# New ports collection makefile for:	mx
# Date created:		30 Mar 2011
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#  $MCom: ports/graphics/clutter/Makefile,v 1.45 2011/03/21 14:46:23 kwm Exp $
#

PORTNAME=	mx
PORTVERSION=	1.0.4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://source.clutter-project.org/sources/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter based widget toolkit

LIB_DEPENDS=	clutter-glx-1.0.0:${PORTSDIR}/graphics/clutter \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

LICENSE=	LGPL21
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	glib20 gtk20 intlhack ltverhack
USE_LDCONFIG=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
