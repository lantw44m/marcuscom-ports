# New ports collection makefile for:   mm-common
# Date Created:			27 Aug 2009
# Whom:				Koop Mast<kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/mm-common/Makefile,v 1.2 2009/08/28 16:58:12 kwm Exp $
#

PORTNAME=	mm-common
PORTVERSION=	0.7.2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Commen build infrastructure for the GNOME C++ binding libraries

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

USE_GNOME=	gnomehack
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
#CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
#		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
