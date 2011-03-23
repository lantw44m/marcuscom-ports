# New ports collection makefile for:	atkmm
# Date created:				24 June 2010
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/atkmm/Makefile,v 1.6 2011/01/12 18:54:02 kwm Exp $
#

PORTNAME=	atkmm
PORTVERSION=	2.22.3
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for ATK API library

BUILD_DEPENDS=	mm-common-prepare:${PORTSDIR}/devel/mm-common
LIB_DEPENDS=	glibmm-2.4.1:${PORTSDIR}/devel/glibmm

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_GNOME=	gnomehack atk
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include " \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-documentation

.include <bsd.port.mk>
