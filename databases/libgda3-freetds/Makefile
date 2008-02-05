# New ports collection makefile for:	libgda2
# Date created:				02 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTREVISION?=	0
CATEGORIES=	databases gnome
PKGNAMESUFFIX?=	-freetds

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides freetds backend for the libgda3 library

MASTERDIR=	${.CURDIR}/../libgda3
BUILD_WRKSRC=	${WRKSRC}/providers/postgres/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA3_SLAVE=	freetds

USE_GNOME+=	libgda3

.include "${MASTERDIR}/Makefile"
