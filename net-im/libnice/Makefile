# New ports collection makefile for:	libnice
# Date created:				27 February 2009
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libnice
PORTVERSION=	0.1.0
CATEGORIES=	net-im devel
MASTER_SITES=	http://nice.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library and transmitter that implements ICE-19

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack pkgconfig glib20 ltverhack
USE_GSTREAMER=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DHAVE_GETIFADDRS" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
	    	's|-Wno-missing-field-initializers|#|g'
	@${REINPLACE_CMD} -e 's|-Wno-missing-field-initializers|#|g' \
	    	${WRKSRC}/common.mk
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in \
		${WRKSRC}/configure ${WRKSRC}/config.h.in

.include <bsd.port.mk>
