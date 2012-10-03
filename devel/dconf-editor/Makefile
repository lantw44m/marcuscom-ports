# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/dconf/Makefile,v 1.29 2012/05/28 11:45:14 kwm Exp $

PORTNAME=	dconf-editor

COMMENT=	configuration editor for dconf

DCONF_SLAVE=	editor

MASTERDIR=	${.CURDIR}/../dconf

PLIST=		${.CURDIR}/pkg-plist

do-build:
	@cd ${WRKSRC}/editor && ${GMAKE}

do-install:
	@cd ${WRKSRC}/editor && ${GMAKE} install

.include "${MASTERDIR}/Makefile"
