# New ports collection makefile for:	avahi-gtk
# Date created:				31 July 2007
# Whom:					Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	avahi-header
PORTREVISION=	0
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Install an avahi-gtk* header to avoid conflict

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-ui
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST_FILES=	include/avahi-ui/avahi-ui.h
PLIST_DIRS=	include/avahi-ui

AVAHI_SLAVE=	header

NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/include/avahi-ui
	${INSTALL_DATA} ${BUILD_WRKSRC}/avahi-ui.h \
		${PREFIX}/include/avahi-ui/

.include "${MASTERDIR}/Makefile"
