# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/libgda5-ui/Makefile,v 1.5 2011/10/13 13:29:51 kwm Exp $

PORTREVISION=	1
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	5-ui

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The libgda 5 ui library

MASTERDIR=	${.CURDIR}/../libgda5
PLIST=		${.CURDIR}/pkg-plist

CONFLICTS=	libgda4-4.*

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
