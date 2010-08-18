# New ports collection makefile for:	llibfolks
# Date created:				23 July 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net-im/folks/Makefile,v 1.1 2010/08/18 12:45:58 kwm Exp $
#

PORTNAME=	folks
PORTVERSION=	0.1.14
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	library to aggregates people from multiple sources

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS= 	gee.2:${PORTSDIR}/devel/libgee \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include " \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
