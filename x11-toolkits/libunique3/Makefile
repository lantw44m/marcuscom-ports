# New ports collection makefile for:   libunique
# Date created:			22 Feb 2009
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	libunique3
PORTVERSION=	2.90.0.a1
CATEGORIES=	x11-toolkits
#MASTER_SITES=	GNOME/sources/${PORTNAME:S/3//}/${PORTVERSION:R}/
MASTER_SITES=	http://rainbow-runner.nl/~kwm/
DISTNAME=	${PORTNAME:S/3//}-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library for single instance applications

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus

USE_XORG=	ice
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gtk30 gnomeprefix ltverhack:0
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-maintainer-flags --enable-gtk-doc-html=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|g' \
		-e 's|unique tests doc|unique tests|g' \
		${WRKSRC}/configure ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
