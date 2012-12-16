# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/dconf-editor/Makefile,v 1.1 2012/10/03 17:57:17 kwm Exp $

PORTNAME=	dconf
PKGNAMESUFFIX=	-editor

COMMENT=	configuration editor for dconf

DCONF_SLAVE=	editor

MASTERDIR=	${.CURDIR}/../dconf

PLIST=		${.CURDIR}/pkg-plist

do-build:
	@cd ${WRKSRC}/editor && ${GMAKE}

do-install:
	@cd ${WRKSRC}/editor && ${GMAKE} install

.include "${MASTERDIR}/Makefile"
