# New ports collection makefile for:	clutter-gtk
# Date created:		2008-12-25
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clutter-gtk
PORTVERSION=	0.9.0.a20090616
CATEGORIES=	graphics
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	kwm
#http://www.clutter-project.org/sources/${PORTNAME}/0.8/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a/./}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+ Integration library for Clutter

LIB_DEPENDS=	clutter-glx-0.9:${PORTSDIR}/graphics/clutter

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack gtk20 ltverhack gnomeprefix
USE_XORG=	xp x11
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
