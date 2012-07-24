# New ports collection makefile for:	clutter
# Date created:		2008-12-25
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#  $MCom: ports/graphics/cogl/Makefile,v 1.6 2012/05/20 12:31:46 kwm Exp $
#

PORTNAME=	cogl
PORTVERSION=	1.10.4
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter OpenGL abstraction library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection

CONFLICTS=	clutter-1.6.[0-9]*

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	pkgconfig gdkpixbuf2 gnomehack ltverhack gnomeprefix atk pango
USE_GL=		gl
USE_XORG=	glproto x11 xfixes xdamage xcomposite xi
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-x
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
