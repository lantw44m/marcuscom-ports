# New ports collection makefile for:	yelp
# Date created:				18 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/yelp-xsl/Makefile,v 1.10 2011/03/09 22:10:01 kwm Exp $
#

PORTNAME=	yelp-xsl
PORTVERSION=	2.91.92
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	DocBook XSLT stylesheets for yelp

LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack pkgconfig libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

# Around the time GCC stack protection (aka Propolice) for userland
# was enabled on src/share/mk/bsd.sys.mk
# SVN rev 180012 on 2008-06-25 21:33:28Z by ru
.if ${OSVERSION} >= 800040
LDFLAGS+=	-fstack-protector
.endif

.include <bsd.port.post.mk>
