# New ports collection makefile for:	mergeant
# Date created:				14 September 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/mergeant/Makefile,v 1.13 2005/07/09 06:11:49 adamw Exp $
#

PORTNAME=	mergeant
PORTVERSION=	0.61
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.61
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

.include <bsd.port.mk>
