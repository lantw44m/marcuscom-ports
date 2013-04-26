# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net/avahi-gtk3/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTREVISION=	0
CATEGORIES=	net
PKGNAMESUFFIX=	-gtk3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gtk+ 3 library to the Avahi mDNS system

LIB_DEPENDS=	avahi-common.3:${PORTSDIR}/net/avahi-app
RUN_DEPENDS=	avahi-header>=0.6:${PORTSDIR}/net/avahi-header

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-ui
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

CONFIGURE_ARGS+=--disable-silent-rules

AVAHI_SLAVE=	gtk3
AVAHI_PKGCONFIG=avahi-ui-gtk3.pc

USE_GNOME=	gnomehack ltverhack intltool gtk30

do-build:
	@(cd ${WRKSRC}/avahi-ui; ${GMAKE} libavahi-ui-gtk3.la)

do-install:
	@(cd ${WRKSRC}/avahi-ui; ${GMAKE} install-libLTLIBRARIES)

.include "${MASTERDIR}/Makefile"
