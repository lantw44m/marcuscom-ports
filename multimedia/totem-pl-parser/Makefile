# New ports collection makefile for:	totem-pl-parser
# Date created:		2007-12-04
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/multimedia/totem-pl-parser/Makefile,v 1.3 2008/01/08 22:57:47 kwm Exp $
#

PORTNAME=	totem-pl-parser
PORTVERSION=	2.21.90
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject-based library to parse a host of playlist formats

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnomevfs2
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
