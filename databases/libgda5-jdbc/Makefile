# New ports collection makefile for:	libgda4-java
# Date created:				10 Mar 2009
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION?=	0
CATEGORIES=	databases gnome
PKGNAMESUFFIX?=	5-jdbc

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides Java DB Connector backend for the libgda5 library

MASTERDIR=	${.CURDIR}/../libgda5
BUILD_WRKSRC=	${WRKSRC}/providers/jdbc
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA5_SLAVE=	jdbc

.include "${MASTERDIR}/Makefile"
