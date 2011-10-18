# New ports collection makefile for:	yelp-tools
# Date created:				17 Sep 2011
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/textproc/yelp-tools/Makefile,v 1.4 2011/10/08 09:50:01 kwm Exp $
#

PORTNAME=	yelp-tools
PORTVERSION=	3.2.1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	utilities to help manage documentation for Yelp and the web

BUILD_DEPENDS=	yelp-xsl>=3.1.5:${PORTSDIR}/textproc/yelp-xsl \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt

USE_GETTEXT=	yes
USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack pkgconfig libxml2
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

# Around the time GCC stack protection (aka Propolice) for userland
# was enabled on src/share/mk/bsd.sys.mk
# SVN rev 180012 on 2008-06-25 21:33:28Z by ru
.if ${OSVERSION} >= 800040
LDFLAGS+=	-fstack-protector
.endif

.include <bsd.port.post.mk>
