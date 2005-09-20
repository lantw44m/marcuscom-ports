# New ports collection makefile for:	gnomecommon
# Date created:				04 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/devel/gnomecommon/Makefile,v 1.4 2005/07/25 22:51:31 ahze Exp $
#

PORTNAME=	gnomecommon
PORTVERSION=	2.12.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-common/2.12
DISTNAME=	gnome-common-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common automake macros for GNOME and GNOME 2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig gnometarget
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
