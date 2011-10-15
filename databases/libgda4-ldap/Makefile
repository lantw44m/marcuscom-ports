# New ports collection makefile for:	libgda2
# Date created:				02 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/libgda4-ldap/Makefile,v 1.2 2011/10/13 13:29:49 kwm Exp $
#

PORTREVISION=	0
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	4-ldap

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides ldap access for the libgda4 library

MASTERDIR=	${.CURDIR}/../libgda4
BUILD_WRKSRC=	${WRKSRC}/providers/ldap/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA4_SLAVE=	ldap

.include "${MASTERDIR}/Makefile"
