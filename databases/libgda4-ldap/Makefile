# New ports collection makefile for:	libgda2
# Date created:				02 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTREVISION?=	0
CATEGORIES=	databases gnome
PKGNAMESUFFIX?=	-ldap

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides ldap access for the libgda4 library

MASTERDIR=	${.CURDIR}/../libgda4
BUILD_WRKSRC=	${WRKSRC}/providers/ldap/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA4_SLAVE=	ldap

.include "${MASTERDIR}/Makefile"
