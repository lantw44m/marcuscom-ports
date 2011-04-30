# New ports collection makefile for:	vala-vapigen
# Date created:				
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/lang/vala-vapigen/Makefile,v 1.4 2010/12/01 14:59:18 kwm Exp $
#

PORTREVISION=	0
CATEGORIES=	devel gnome
PKGNAMESUFFIX=	-vapigen

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The vapigen program from vala

USE_GMAKE=	yes

MASTERDIR=	${.CURDIR}/../vala
BUILD_WRKSRC=	${WRKSRC}/vapigen
INSTALL_WRKSRC=	${WRKSRC}/vapigen
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

VALA_SLAVE=	yes

.include "${MASTERDIR}/Makefile"
