# New ports collection makefile for:	libgda4-bdb
# Date created:				28 February 2009
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/databases/libgda4-bdb/Makefile,v 1.7 2011/03/03 10:21:36 kwm Exp $
#

PORTREVISION=	0
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	4-bdb

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides Berkeley DB backend for the libgda4 library

MASTERDIR=	${.CURDIR}/../libgda4
BUILD_WRKSRC=	${WRKSRC}/providers/bdb/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA4_SLAVE=	bdb

.include "${MASTERDIR}/Makefile"
