# New ports collection makefile for:	evolution-webcal
# Date created:				Mon Apr 26 18:08:00 CEST 2004
# Whom:					Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	webcal
PORTVERSION=	1.0.6
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PKGNAMEPREFIX}${PORTNAME}/1.0
PKGNAMEPREFIX=	evolution-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	kwm@rainbow-runner.nl
COMMENT=	Webcal(endar) handler for gnome

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack evolutiondataserver libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
