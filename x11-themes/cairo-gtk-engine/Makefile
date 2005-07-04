# New ports collection makefile for:	cairo-gtk-engine
# Date created:		2005-07-04
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom$

PORTNAME=	cairo-gtk-engine
PORTVERSION=	0.0.0
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~ahze/distfiles/
MASTER_SITE_SUBDIR=	ahze

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Cairo-gtk theme engine and themes

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack gtk20
USE_X_PREFIX=	yes

.include <bsd.port.mk>
