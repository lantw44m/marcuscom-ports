# New ports collection makefile for:	totem-pl-parser
# Date created:		2007-12-04
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/totem-pl-parser/Makefile,v 1.1 2007/12/04 14:40:48 ahze Exp $

PORTNAME=	totem-pl-parser
PORTVERSION=	2.21.6
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject-based library to parse a host of playlist formats

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
USE_GNOME=	gnomehack gnomeprefix gnomevfs2

.include <bsd.port.mk>
