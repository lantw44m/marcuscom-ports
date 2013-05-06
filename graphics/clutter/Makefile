# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#  $MCom: ports/trunk/graphics/clutter/Makefile 17271 2013-04-01 15:16:27Z kwm $

PORTNAME=	clutter
PORTVERSION=	1.12.2
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL based interactive canvas library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	json-glib-1.0:${PORTSDIR}/devel/json-glib \
		cogl:${PORTSDIR}/graphics/cogl

USES=		pkgconfig gettext pathfix
USE_GMAKE=	yes
USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gdkpixbuf2 ltverhack gnomeprefix atk pango
USE_GL=		gl
USE_XORG=	glproto x11 xfixes xdamage xcomposite xi
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-x --enable-conformance=no \
		--disable-gdk-backend

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS} -fno-omit-frame-pointer
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
