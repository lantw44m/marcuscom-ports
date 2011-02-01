# New ports collection makefile for:	folks
# Date created:				23 July 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net-im/folks/Makefile,v 1.11 2011/01/23 18:30:20 marcus Exp $
#

PORTNAME=	folks
PORTVERSION=	0.3.4
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	library to aggregates people from multiple sources

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	gee.2:${PORTSDIR}/devel/libgee \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include " \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=20

.include <bsd.port.mk>
