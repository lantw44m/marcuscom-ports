# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/lang/vala-vapigen/Makefile,v 1.6 2012/05/15 15:18:54 kwm Exp $

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
