# New ports collection makefile for:	vty-checker
# Date created:		02 February 2008
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/vty-checker/Makefile,v 1.1 2008/02/02 23:58:48 marcus Exp $
#
# This port is self contained in the src directory.
#

PORTNAME=	vty-checker
PORTVERSION=	1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A small tool to verify all VTY lines have been configured

WRKSRC=		${WRKDIR}/src
SRC=		${.CURDIR}/src

PLIST_FILES=	bin/vty-checker

do-fetch:
	@${DO_NADA}

pre-patch:
	@${CP} -R ${SRC} ${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vty-checker ${PREFIX}/bin/vty-checker

.include <bsd.port.mk>
