# New ports collection makefile for:	clutter
# Date created:		2008-12-25
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD: ports/graphics/clutter/Makefile,v 1.6 2009/11/28 20:05:41 marcus Exp $
#

PORTNAME=	clutter
PORTVERSION=	1.1.4
CATEGORIES=	graphics
MASTER_SITES=	GNOME \
		http://www.clutter-project.org/sources/${PORTNAME}/1.0/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL based interactive canvas library

BUILD_DEPENDS=	${LOCALBASE}/share/gir-1.0/Pango-1.0.gir:${PORTSDIR}/x11-toolkits/gir-repository-pango
RUN_DEPENDS=	${LOCALBASE}/share/gir-1.0/Pango-1.0.gir:${PORTSDIR}/x11-toolkits/gir-repository-pango

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	pkgconfig gtk20 gnomehack ltverhack gnomeprefix
USE_GL=		gl
USE_XORG=	glproto x11 xfixes xdamage xcomposite xi
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-x --with-json=internal
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>