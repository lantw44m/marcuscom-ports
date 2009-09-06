# New ports collection makefile for:	libproxy-mozjs
# Date created:		26 February 2009
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/net/libproxy-mozjs/Makefile,v 1.3 2009/07/31 13:54:44 dinoex Exp $
#

PORTREVISION=	2
CATEGORIES=	net devel
PKGNAMESUFFIX=	-mozjs

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mozilla Javascript plug-in for libproxy

LIB_DEPENDS=	proxy.0:${PORTSDIR}/net/libproxy

MASTERDIR=	${.CURDIR}/../libproxy
BUILD_WRKSRC=	${WRKSRC}/src/plugins
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
USE_GECKO=	libxul
CONFIGURE_ARGS=--without-gnome --without-kde --without-webkit \
		--with-mozjs --without-networkmanager --without-python \
		--without-envvar --without-file

LIBPROXY_SLAVE=	yes

.include "${MASTERDIR}/Makefile"
