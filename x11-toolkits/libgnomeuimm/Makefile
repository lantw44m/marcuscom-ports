# New ports collection makefile for:    libgnomeuimm
# Date created:         22 May 2003
# Whom:                 Alexander Nedotsukov <bland@mail.ru>
#
# $FreeBSD: ports/x11-toolkits/libgnomeuimm/Makefile,v 1.7 2003/10/12 15:27:25 bland Exp $
#

PORTNAME=	libgnomeuimm
PORTVERSION=	2.5.0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.5
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libgnomeui library

LIB_DEPENDS=	gnomemm-2.5.1:${PORTSDIR}/x11/libgnomemm \
		gnomecanvasmm-2.5.1:${PORTSDIR}/graphics/libgnomecanvasmm \
		gconfmm-2.5.1:${PORTSDIR}/devel/gconfmm \
		glademm-2.3.1:${PORTSDIR}/devel/libglademm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack lthack libgnomeui
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static

PLIST_SUB=	VERSION="2.5" API_VERSION="2.6"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=  ${PATCHDIR}/extra-patch-old_gcc_bugs
.endif

.include <bsd.port.post.mk>
