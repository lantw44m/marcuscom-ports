# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#  $MCom$

PORTNAME=	cogl
PORTVERSION=	1.12.2
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter OpenGL abstraction library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	clutter-1.6.[0-9]*

USES=		pkgconfig gettext pathfix
USE_GMAKE=	yes
USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gdkpixbuf2 ltverhack gnomeprefix atk pango introspection:build
USE_GL=		gl
USE_XORG=	glproto x11 xfixes xdamage xcomposite xi
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-x
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
