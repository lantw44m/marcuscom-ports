# New ports collection makefile for:	gnome2-office
# Date created:				07 January 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/editors/gnome2-office/Makefile,v 1.23 2005/04/18 21:02:55 marcus Exp $
#

PORTNAME=	gnome2-office
PORTVERSION=	2.11.3
CATEGORIES=	editors gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 office applications

RUN_DEPENDS=	gnumeric:${PORTSDIR}/math/gnumeric \
		planner:${PORTSDIR}/deskutils/planner \
		dia:${PORTSDIR}/graphics/dia \
		glabels:${PORTSDIR}/deskutils/glabels \
		abiword:${PORTSDIR}/editors/abiword \
		mergeant:${PORTSDIR}/databases/mergeant

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
