# New ports collection makefile for:	mergeant
# Date created:				14 September 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/mergeant/Makefile,v 1.12 2005/07/01 17:55:37 marcus Exp $
#

PORTNAME=	mergeant
PORTVERSION=	0.60
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.60
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provide uniform access to data sources for the GNOME 2 environment

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomedb libgnomeprintui
USE_PERL5=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_OMF=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

#remove this with the next update
post-patch:
	@${REINPLACE_CMD} -e "s|libgda|libgda-2.0|g; \
		s|libgnomedb|libgnomedb-2.0|g" \
		${WRKSRC}/configure

.include <bsd.port.mk>
