# New ports collection makefile for:	libgda2
# Date created:				02 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/libgda4-postgresql/Makefile,v 1.3 2010/10/18 12:47:12 kwm Exp $
#

PORTREVISION?=	0
CATEGORIES=	databases gnome
PKGNAMESUFFIX?=	-ui

CONFLICTS=	libgda4-4.*

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	libgda 5 ui library

MASTERDIR=	${.CURDIR}/../libgda5
PLIST=		${.CURDIR}/pkg-plist

LIBGDA5_SLAVE=	ui

do-build:
	@cd ${WRKSRC}/libgda-ui && ${GMAKE}
	@cd ${WRKSRC}/control-center && ${GMAKE}
	@cd ${WRKSRC}/tools/browser && ${GMAKE}

do-install:
	@cd ${WRKSRC}/libgda-ui && ${GMAKE} install
	@cd ${WRKSRC}/control-center && ${GMAKE} install
	@cd ${WRKSRC}/tools/browser && ${GMAKE} install

.include "${MASTERDIR}/Makefile"
