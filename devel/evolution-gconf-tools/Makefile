# New ports collection makefile for:	evolution-gconf-tools
# Date created:		2005-07-22
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	evolution-gconf-tools
PORTVERSION=	0.1.6
CATEGORIES=	devel
MASTER_SITES=	http://people.redhat.com/dmalcolm/evolution-gconf-tools/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Scripts to make it easier to work with Evolution's configuration

RUN_DEPENDS=	evolution:${PORTSDIR}/mail/evolution

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${SH}|' \
		${WRKSRC}/lib/*

.include <bsd.port.mk>
