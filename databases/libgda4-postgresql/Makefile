# New ports collection makefile for:	libgda2
# Date created:				02 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/databases/libgda4-postgresql/Makefile,v 1.6 2010/11/20 15:36:27 kwm Exp $
#   $MCom: ports/databases/libgda4-postgresql/Makefile,v 1.5 2011/10/13 13:29:49 kwm Exp $
#

PORTREVISION=	0
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	4-postgresql

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides postgresql access for the libgda4 library

MASTERDIR=	${.CURDIR}/../libgda4
BUILD_WRKSRC=	${WRKSRC}/providers/postgres/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA4_SLAVE=	postgresql

.include "${MASTERDIR}/Makefile"
