# New ports collection makefile for:	kaffeine-mozilla
# Date created:				2004-05-25
# Whom:					arved
#
# $FreeBSD$
#    $MCom: ports/multimedia/kaffeine-mozilla/Makefile,v 1.1 2006/07/21 19:38:13 ahze Exp $

PORTNAME=	kaffeine-mozilla
PORTVERSION=	0.2
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kaffeine

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kaffeine Mozilla plugin

RUN_DEPENDS=	kaffeine:${PORTSDIR}/multimedia/kaffeine

USE_XLIB=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include"

post-patch:
	${REINPLACE_CMD} -e "s,prefix)/plugins,prefix)/lib/browser_plugins," ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
