# New ports collection makefile for:	contact lookup applet
# Date created:				22 January 2004
# Whom:					kwm@rainbow-runner.nl
#
# $FreeBSD$
#

PORTNAME=	contact
PORTVERSION=	0.9
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.burtonini.com/computing/
PKGNAMESUFFIX=	-lookup-applet
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Gnome pannel applet for easy evolution contact book access

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomehier gnomeprefix gnomehack gnomepanel \
		evolutiondataserver gal2

post-patch:
	@${REINPLACE_CMD} -e 's|mkdir}"|mkdir} -p"|g' \
		${WRKSRC}/install-sh

.include <bsd.port.mk>
