# New ports collection makefile for:	libproxy-webkit
# Date created:		26 February 2009
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTREVISION=	0
CATEGORIES=	net www
PKGNAMESUFFIX=	-webkit

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	WebKit Javascript plug-in for libproxy

LIB_DEPENDS=	proxy.1:${PORTSDIR}/net/libproxy \
    		webkit-1.0.13:${PORTSDIR}/www/webkit-gtk2

MASTERDIR=	${.CURDIR}/../libproxy
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

LIBPROXY_SLAVE=	webkit

do-install:
#	${MKDIR} 
	${INSTALL_LIB} ${WRKSRC}/libproxy/pacrunner_webkit.so \
		${PREFIX}/lib/libproxy/0.4.6/modules/

.include "${MASTERDIR}/Makefile"
