# New ports collection makefile for:	gconf2
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD: ports/devel/gconf2/Makefile,v 1.64 2005/03/12 10:39:14 marcus Exp $
#

PORTNAME=	gconf2
PORTVERSION=	2.11.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/GConf/2.11
DISTNAME=	GConf-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A configuration database system for GNOME

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehier gnomehack orbit2 gtk20 libxml2 linc
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
#		--enable-gconf-source=${PREFIX}/etc/gconf/schemas \

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAN1=		gconftool-2.1

.include <bsd.port.pre.mk>

.include <bsd.port.post.mk>
