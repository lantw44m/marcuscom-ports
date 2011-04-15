# New ports collection makefile for:	avahi-gtk
# Date created:				31 July 2007
# Whom:					Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net/avahi-header/Makefile,v 1.2 2011/03/31 02:06:52 mezz Exp $
#

PORTREVISION=	1
CATEGORIES=	net
PKGNAMESUFFIX=	-header

COMMENT=	Install an avahi-gtk* header to avoid conflict

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-ui
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	header

NO_BUILD=	yes

do-install:
	${MKDIR} ${PREFIX}/include/avahi-ui
	${INSTALL_DATA} ${BUILD_WRKSRC}/avahi-ui.h \
		${PREFIX}/include/avahi-ui/

.include "${MASTERDIR}/Makefile"
