# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD: devel/dconf-editor/Makefile 313633 2013-03-08 10:51:34Z kwm $
#   $MCom$

PORTNAME=	dconf
PORTREVISION=	1
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
