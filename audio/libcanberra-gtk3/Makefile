# New ports collection makefile for:	libcanberra
# Date created:				05 August 2008
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTREVISION=	0
CATEGORIES=	audio devel
PKGNAMESUFFIX=	-gtk3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the Freedesktop sound theme spec

MASTERDIR=	${.CURDIR}/../../audio/libcanberra
SLAVEPORT=	gtk3
PLIST=		${.CURDIR}/pkg-plist

do-build:
	cd ${WRKSRC} && ${GMAKE} libcanberra-gtk3.pc
	cd ${WRKSRC}/src && ${GMAKE} libcanberra-gtk3.la
	cd ${WRKSRC}/src && ${GMAKE} libcanberra-gtk3-module.la

do-install:
	${INSTALL_DATA} ${WRKSRC}/libcanberra-gtk3.pc \
		${PREFIX}/libdata/pkgconfig/
.for i in .a .la .so .so.0
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libcanberra-gtk3${i} \
		${PREFIX}/lib/
.endfor
	cd ${WRKSRC}/src && ${GMAKE} install-gtk3moduleLTLIBRARIES

.include "${MASTERDIR}/Makefile"
