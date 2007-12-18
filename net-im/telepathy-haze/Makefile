# New ports collection makefile for:	telepathy-haze
# Date created:		2007-10-29
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-stable/net-im/telepathy-haze/Makefile,v 1.1 2007/10/29 17:13:28 ahze Exp $

PORTNAME=	haze
PORTVERSION=	0.1.2
CATEGORIES=	net-im
MASTER_SITES=	http://ftp.de.debian.org/debian/pool/main/t/telepathy-haze/
#MASTER_SITES=	http://salami.ox.compsoc.net/~resiak/haze/
PKGNAMEPREFIX=	telepathy-
DISTNAME=	telepathy-haze_${PORTVERSION}.orig

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Libpurple connection manager for telepathy

LIB_DEPENDS=	purple.2:${PORTSDIR}/net-im/libpurple \
		telepathy-glib.2:${PORTSDIR}/net-im/telepathy-glib

WRKSRC=	${WRKDIR}/telepathy-${PORTNAME}-${DISTVERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
