# New ports collection makefile for:    json-glib
# Date created:         		25 December 2008
# Whom:                 		Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/json-glib/Makefile,v 1.2 2009/07/19 19:46:43 marcus Exp $
#

PORTNAME=	json-glib
PORTVERSION=	0.7.6
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	JSON (RFC 4627) interface for Glib

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gnomehack gnomeprefix ltverhack
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
