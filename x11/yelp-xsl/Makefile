# New ports collection makefile for:	yelp
# Date created:				18 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/yelp-xsl/Makefile,v 1.5 2010/12/18 11:46:09 kwm Exp $
#

PORTNAME=	yelp-xsl
PORTVERSION=	2.91.9
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
#MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

.include <bsd.port.pre.mk>

# Around the time GCC stack protection (aka Propolice) for userland
# was enabled on src/share/mk/bsd.sys.mk
# SVN rev 180012 on 2008-06-25 21:33:28Z by ru
.if ${OSVERSION} >= 800040
LDFLAGS+=	-fstack-protector
.endif

.include <bsd.port.post.mk>
