# New ports collection makefile for:	libgda4-java
# Date created:				10 Mar 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD: ports/databases/libgda4-jdbc/Makefile,v 1.6 2011/03/03 10:21:36 kwm Exp $
#

PORTREVISION?=	0
CATEGORIES=	databases gnome
PKGNAMESUFFIX?=	4-jdbc

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides Berkeley DB backend for the libgda4 library

MASTERDIR=	${.CURDIR}/../libgda4
BUILD_WRKSRC=	${WRKSRC}/providers/jdbc
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA4_SLAVE=	jdbc

.include "${MASTERDIR}/Makefile"
