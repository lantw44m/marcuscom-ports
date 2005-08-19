# New ports collection makefile for:	present
# Date created:		2005-06-13
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/present/Makefile,v 1.4 2005/07/01 18:00:51 marcus Exp $
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
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"
USE_GNOME=	gnomehack intlhack

.include <bsd.port.mk>
