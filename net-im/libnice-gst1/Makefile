# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net/libproxy-gnome/Makefile,v 1.1 2011/01/12 13:10:53 kwm Exp $

PORTREVISION=	0
PKGNAMESUFFIX=	-gst1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GStreamer 1 plugin from libnice

LIB_DEPENDS=	nice:${PORTSDIR}/net-im/libnice

MASTERDIR=	${.CURDIR}/../libnice
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

BUILD_WRKSRC=	${WRKSRC}/gst
INSTALL_WRKSRC=	${WRKSRC}/gst

LIBNICE_SLAVE=	gstreamer1

.include "${MASTERDIR}/Makefile"
