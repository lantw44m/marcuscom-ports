# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/misc/gnome-devel-docs/Makefile 18610 2013-06-30 16:33:05Z marcus $

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

NO_STAGE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake
USE_GNOME=	gnomehier
INSTALLS_OMF=	yes

.include <bsd.port.mk>
