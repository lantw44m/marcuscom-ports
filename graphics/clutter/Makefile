# New ports collection makefile for:	clutter
# Date created:		2008-12-25
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD: ports/graphics/clutter/Makefile,v 1.3 2009/03/04 07:36:52 marcus Exp $
#

PORTNAME=	clutter
PORTVERSION=	0.9.3.a20090506
CATEGORIES=	graphics
MASTER_SITES=	LOCAL
MASTER_SITE_SUBDIR=	kwm
#http://www.clutter-project.org/sources/${PORTNAME}/0.8/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a/./}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL based interactive canvas library

LIB_DEPENDS=	json-glib-1.0:${PORTSDIR}/devel/json-glib

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	pkgconfig gtk20 gnomehack ltverhack gnomeprefix
USE_GL=		gl
USE_XORG=	glproto x11 xfixes xdamage xcomposite xi
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-x --with-json=check
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
