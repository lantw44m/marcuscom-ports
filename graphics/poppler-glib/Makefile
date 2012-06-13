# New ports collection makefile for:	poppler-gtk
# Date created:		2006-01-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD: ports/graphics/poppler-glib/Makefile,v 1.3 2012/06/01 05:20:37 dinoex Exp $
#   $MCom$
#

PORTREVISION=	0
PKGNAMESUFFIX=	-glib

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Glib bindings to poppler

MASTERDIR=	${.CURDIR}/../../graphics/poppler
SLAVEPORT=	glib
PLIST=	${.CURDIR}/pkg-plist

pre-build:
	cd ${WRKSRC}/poppler && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} libpoppler-cairo.la

.include "${MASTERDIR}/Makefile"
