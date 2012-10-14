# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/graphics/poppler-qt4/Makefile,v 1.17 2012/06/13 12:29:04 kwm Exp $

PORTREVISION=	0
PKGNAMESUFFIX=	-qt4

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Qt4 bindings to poppler

MASTERDIR=	${.CURDIR}/../../graphics/poppler
SLAVEPORT=	qt4
PLIST=		${.CURDIR}/pkg-plist

pre-build:
	cd ${WRKSRC}/poppler && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} libpoppler-arthur.la

.include "${MASTERDIR}/Makefile"
