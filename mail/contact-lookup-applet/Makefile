# New ports collection makefile for:	contact lookup applet
# Date created:				22 January 2004
# Whom:					kwm@rainbow-runner.nl
#
# $FreeBSD$
#

PORTNAME=	contact
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.burtonini.com/computing/
PKGNAMESUFFIX=	-lookup-applet
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	kwm@rainbow-runner.nl
COMMENT=	Gnome pannel applet for easy evolution contact book access

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehier gnomeprefix gnomehack gnomepanel evolutiondataserver

.include <bsd.port.mk>
