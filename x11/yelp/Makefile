# New ports collection makefile for:	yelp
# Date created:				18 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD: ports/x11/yelp/Makefile,v 1.26 2003/11/10 19:50:27 marcus Exp $
#

PORTNAME=	yelp
PORTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.5
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A help browser for the GNOME 2 desktop

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui libgtkhtml
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

#post-patch:
#	@${REINPLACE_CMD} -e 's|\@prefix\@/share|\@datadir\@|g' \
#		${WRKSRC}/stylesheets/docbook/catalog.in

.include <bsd.port.mk>
