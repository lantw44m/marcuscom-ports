# New ports collection makefile for:	poppler
# Date created:         03 March 2005
# Whom:                 marcus@FreeBSD.org
#
# $FreeBSD$
#   $MCom: ports/graphics/poppler/Makefile,v 1.10 2005/08/13 08:19:47 marcus Exp $
#

PORTNAME=	poppler
PORTVERSION=	0.4.0
CATEGORIES=	graphics print
MASTER_SITES=	http://poppler.freedesktop.org/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A PDF rendering library

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomeprefix gnomehack gtk20
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
