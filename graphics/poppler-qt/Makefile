# New ports collection makefile for:	poppler-qt
# Date created:		2006-01-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/graphics/poppler-qt/Makefile,v 1.3 2006/02/01 21:48:19 ahze Exp $

PORTREVISION=	2
PKGNAMESUFFIX=	-qt

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Qt bindings to poppler

MASTERDIR=	${.CURDIR}/../../graphics/poppler
SLAVEPORT=	qt
PLIST=	${.CURDIR}/pkg-plist

BROKEN=Configure script is busted
.include "${MASTERDIR}/Makefile"
