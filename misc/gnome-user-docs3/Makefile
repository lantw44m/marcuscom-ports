# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	gnome-user-docs
PORTVERSION=	3.6.2
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 users guide

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

LATEST_LINK=	gnome-user-docs3
USE_XZ=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes
USES=		pathfix
USE_GNOME=	gnomeprefix gnomehier libxml2:build

.include <bsd.port.mk>
