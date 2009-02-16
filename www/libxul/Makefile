# New ports collection makefile for:	xulrunner
# Date created:		2006-02-20
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/xulrunner/Makefile,v 1.18 2009/02/09 02:43:46 ahze Exp $
#

PORTNAME=	xulrunner
PORTVERSION=	1.9.0.6
PORTREVISION?=	0
CATEGORIES?=	www devel
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	xulrunner/releases/${PORTVERSION}/source/
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Mozilla runtime package that can be used to bootstrap XUL+XPCOM apps

CONFLICTS=	mozilla-[0-9]*
GECKO_PLIST_PRE_DIRS=	lib/${MOZILLA}/bin lib/${MOZILLA}/idl \
			lib/${MOZILLA}/include lib/${MOZILLA}/lib \
			lib/${MOZILLA}/sdk/idl lib/${MOZILLA}/sdk/include

WANT_GNOME=	yes
WANT_PERL=	yes
ALL_TARGET=	default
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes

PORT_MOZCONFIG=	${WRKSRC}/xulrunner/config/mozconfig
MOZ_OPTIONS?=	--with-default-mozilla-five-home=${PREFIX}/lib/${MOZILLA} \
		--disable-javaxpcom --enable-canvas \
		--enable-system-cairo
MOZ_EXTENSIONS=	default,cookie,permissions
OPTIONS=	# Empty, used for generic gecko OPTIONS
USE_GECKO_OPTIONS=	java debug logging optimized_cflags
USE_GECKO=	gecko
MOZ_TOOLKIT=	cairo-gtk2
USE_MOZILLA=	-png -nss -dbm -jpeg
MOZ_PKGCONFIG_FILES=	libxul-embedding-unstable libxul-embedding \
		libxul-unstable	libxul mozilla-gtkmozembed-embedding \
		mozilla-gtkmozembed mozilla-js mozilla-nss mozilla-plugin

.include <bsd.port.mk>
