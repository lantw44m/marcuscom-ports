# New ports collection makefile for:    libglademm
# Date created:         1 Oct 2003
# Whom:                 Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD: ports/databases/libgdamm/Makefile,v 1.27 2009/02/02 01:35:53 araujo Exp $
#   $MCom: ports/databases/libgdamm/Makefile,v 1.13 2009/03/17 16:32:49 kwm Exp $
#

PORTNAME=	libgdamm
PORTVERSION=	3.99.14
PORTREVISION=	1
CATEGORIES=	databases gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libgda3 library

LIB_DEPENDS=	glibmm-2.4:${PORTSDIR}/devel/glibmm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack libgda4
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static

post-patch:
	@${REINPLACE_CMD} -e "s|\(-lglibmm\)|-L\$$(GMM_PROCDIR)/../.. \1|" \
		${WRKSRC}/tools/extra_defs_gen/Makefile.in

.include <bsd.port.mk>
