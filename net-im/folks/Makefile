# New ports collection makefile for:	folks
# Date created:				23 July 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net-im/folks/Makefile,v 1.20 2011/09/25 11:12:00 kwm Exp $
#

PORTNAME=	folks
PORTVERSION=	0.6.3.2
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	library to aggregates people from multiple sources

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	gee.2:${PORTSDIR}/devel/libgee \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib

USE_XZ=		yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack evolutiondataserver3
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include " \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=27

#OPTIONS=	SOCIALWEB "Enable social web backend" on

#.include <bsd.port.options.mk>

#.if defined(WITH_SOCIALWEB)
#LIB_DEPENDS+=	socialweb.0:${PORTSDIR}/www/libsocialweb
#CONFIGURE_ARGS+=--enable-libsocialweb-backend=yes
#.else
CONFIGURE_ARGS+=--enable-libsocialweb-backend=no
#.endif

.include <bsd.port.mk>
