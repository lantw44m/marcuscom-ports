# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTREVISION=	0
CATEGORIES=	net
PKGNAMESUFFIX=	-qt3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Qt 3 bindings to the Avahi mDNS system

LIB_DEPENDS=	avahi-common:${PORTSDIR}/net/avahi-app

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-qt
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	qt3
USES=		pathfix
USE_GNOME=	ltverhack intltool
USE_QT_VER=	3
AVAHI_PKGCONFIG=	avahi-qt3.pc

.include "${MASTERDIR}/Makefile"
