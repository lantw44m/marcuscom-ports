# New ports collection makefile for:   gtkmm2
# Date created:        30 September 2002
# Whom:                Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gtkmm30/Makefile,v 1.20 2012/05/25 10:33:53 kwm Exp $
#

PORTNAME=	gtkmm
PORTVERSION=	3.4.1
PORTREVISION?=	0
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for Gtk+, Pango

USE_XZ=		yes
LATEST_LINK=	gtkmm30

.if !defined(REFERENCE_PORT)

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	glibmm-2.4:${PORTSDIR}/devel/glibmm \
		cairomm-1.0:${PORTSDIR}/graphics/cairomm \
		atkmm-1.6:${PORTSDIR}/accessibility/atkmm \
		pangomm-1.4:${PORTSDIR}/x11-toolkits/pangomm

USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack gtk30 ltverhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-documentation \
		--enable-static=yes

PLIST_SUB=	VERSION="3.0" API_VERSION="3.0"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/tests//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
