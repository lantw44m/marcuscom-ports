# New ports collection makefile for:	libproxy-webkit
# Date created:		26 February 2009
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net/libproxy-webkit/Makefile,v 1.12 2011/01/12 13:10:54 kwm Exp $

PORTREVISION=	1
CATEGORIES=	net www
PKGNAMESUFFIX=	-webkit

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	WebKit Javascript plug-in for libproxy

LIB_DEPENDS=	proxy.1:${PORTSDIR}/net/libproxy \
		webkitgtk-1.0.0:${PORTSDIR}/www/webkit-gtk2

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

LIBPROXY_SLAVE=	webkit

do-install:
#	${MKDIR} 
	${INSTALL_LIB} ${WRKSRC}/libproxy/pacrunner_webkit.so \
		${PREFIX}/lib/libproxy/0.4.6/modules/

.include "${MASTERDIR}/Makefile"
