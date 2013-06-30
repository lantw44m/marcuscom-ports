# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	gnome-devel-docs
PORTVERSION=	2.32.0
PORTREVISION=	1
CATEGORIES=	misc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Documents targeted for GNOME developers

BUILD_DEPENDS=	gnome-doc-prepare:${PORTSDIR}/textproc/gnome-doc-utils
RUN_DEPENDS=	gnome-doc-prepare:${PORTSDIR}/textproc/gnome-doc-utils

CONFLICTS=	gnome-devel-docs-3.[0-9]*

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier
INSTALLS_OMF=	yes

.include <bsd.port.mk>
