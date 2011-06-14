# New ports collection makefile for:   libunique
# Date created:			22 Feb 2009
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/libunique3/Makefile,v 1.5 2011/04/05 18:48:33 kwm Exp $
#

PORTNAME=	libunique
PORTVERSION=	3.0.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library for single instance applications

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

LATEST_LINK=	libunique3
USE_XORG=	ice x11
USE_XZ=		yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
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
