# New ports collection makefile for:    gnome-vfsmm
# Date created:         22 May 2003
# Whom:                 Alexander Nedotsukov <bland@mail.ru>
#
# $FreeBSD: ports/devel/gnome-vfsmm/Makefile,v 1.9 2003/12/07 23:36:16 bland Exp $
#

PORTNAME=	gnome-vfsmm
PORTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for gnomevfs2 library

LIB_DEPENDS=	gtkmm-2.3.3:${PORTSDIR}/x11-toolkits/gtk--2
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack lthack gnomevfs2
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static

PLIST_SUB=	VERSION="2.5" API_VERSION="2.6"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=  ${PATCHDIR}/extra-patch-old_gcc_bugs
.endif

.include <bsd.port.post.mk>
