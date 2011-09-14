# New ports collection makefile for:	clutter
# Date created:		2008-12-25
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#  $MCom: ports/graphics/clutter/Makefile,v 1.48 2011/06/14 15:47:17 kwm Exp $
#

PORTNAME=	clutter
PORTVERSION=	1.6.18
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL based interactive canvas library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	json-glib-1.0.0:${PORTSDIR}/devel/json-glib

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	pkgconfig gdkpixbuf2 gnomehack ltverhack gnomeprefix atk pango
USE_GL=		gl
USE_XORG=	glproto x11 xfixes xdamage xcomposite xi
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-x --enable-conformance=no
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
