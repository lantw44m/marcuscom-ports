# New ports collection makefile for:	gpdf
# Date created:		12 April 2002
# Whom:			Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD: ports/graphics/gpdf/Makefile,v 1.8 2004/04/05 03:11:26 marcus Exp $
#

PORTNAME=	gpdf
PORTVERSION=	2.7.91
CATEGORIES=	graphics print gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.7
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME version of xpdf

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui libgnomeprintui \
		desktopfileutils
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gpdf.schemas

.include <bsd.port.mk>
