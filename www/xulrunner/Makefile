# New ports collection makefile for:	xulrunner
# Date created:		2006-02-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xulrunner
PORTVERSION=	1.8.0.1
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	xulrunner/releases/${PORTVERSION}/source/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Mozilla runtime package that can be used to bootstrap XUL+XPCOM apps

USE_X_PREFIX=	yes
WANT_GNOME=	yes
ALL_TARGET=	default
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GCC=	3.4+

PORT_MOZCONFIG=	${WRKSRC}/xulrunner/config/mozconfig
MOZ_OPTIONS=	--disable-javaxpcom

OPTIONS=	# Empty, used for generic gecko OPTIONS

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/Makefile.common"
.include <bsd.port.post.mk>
