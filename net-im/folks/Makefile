# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net-im/folks/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	folks
PORTVERSION=	0.7.0
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	library to aggregates people from multiple sources

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	gee:${PORTSDIR}/devel/libgee06 \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib

CONFLICTS=	folks-0.4.[0-9]*

USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USES=		pathfix gettext
USE_GNOME=	gnomehier intlhack ltverhack evolutiondataserver3 \
		introspection:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	LIBVER=25 VERSION=33

#OPTIONS=	SOCIALWEB "Enable social web backend" on

#.include <bsd.port.options.mk>

#.if defined(WITH_SOCIALWEB)
#LIB_DEPENDS+=	socialweb.0:${PORTSDIR}/www/libsocialweb
#CONFIGURE_ARGS+=--enable-libsocialweb-backend=yes
#.else
CONFIGURE_ARGS+=--enable-libsocialweb-backend=no
#.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^build_old_libs=yes|build_old_libs=no|g' \
		${WRKDIR}/gnome-libtool

.include <bsd.port.mk>
