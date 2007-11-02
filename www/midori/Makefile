# New ports collection makefile for:	midori
# Date created:		2007-10-21
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-experimental/www/midori/Makefile,v 1.1 2007/10/22 00:57:03 ahze Exp $

PORTNAME=	midori
PORTVERSION=	0.0.10
CATEGORIES=	www
MASTER_SITES=	http://software.twotoasts.de/media/${PORTNAME}/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Lightweight web browser using webkit browser engine

LIB_DEPENDS=	WebKitGtk.1:${PORTSDIR}/www/webkit \
		sexy.2:${PORTSDIR}/x11-toolkits/libsexy

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
