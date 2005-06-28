# New ports collection makefile for:	present
# Date created:		2005-06-13
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	present
PORTVERSION=	0.0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.0

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A library for reading Microsoft PowerPoint(tm) documents

LIB_DEPENDS=	goffice-1.0:${PORTSDIR}/devel/goffice

USE_BZIP2=	yes
USE_LIBTOOL_VER=15

CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"
USE_GNOME=	gnomehack intlhack

.include <bsd.port.mk>
