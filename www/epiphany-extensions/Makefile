# Ports collection Makefile for:	epiphany-extensions
# Date created:				30 December 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/epiphany-extensions/Makefile,v 1.68 2006/03/13 07:09:46 mezz Exp $
#

PORTNAME=	epiphany
PORTVERSION=	2.14.0.1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}${PKGNAMESUFFIX}/${PORTVERSION:C/^([0-9]+)\.([0-9]+).*/\1.\2/}
PKGNAMESUFFIX=	-extensions
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of add-ons for the Epiphany web browser

BUILD_DEPENDS=	epiphany:${PORTSDIR}/www/epiphany
RUN_DEPENDS=	epiphany:${PORTSDIR}/www/epiphany

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GECKO=	firefox mozilla seamonkey
USE_GNOME=	gnomeprefix gnomehack intlhack gnometarget
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-extensions="all" \
		--with-mozilla=${GECKO}

PLIST_SUB=	VERSION="2.14" EPHY_VERSION="2.14"

.if defined(PACKAGE_BUILDING) || defined(PARALLEL_PACKAGE_BUILD)
.undef WITHOUT_OPENSP
WITH_OPENSP=	yes
.endif

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"

.if defined(WITH_OPENSP) || exists(${LOCALBASE}/lib/libosp.so)
CONFIGURE_ARGS+=	--enable-opensp=yes
.else
CONFIGURE_ARGS+=	--disable-opensp
.endif

.if exists(${LOCALBASE}/share/pygtk/2.0/defs/epiphany.defs)
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
PLIST_SUB+=	PYTHON=""
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

pre-everything::
	@${ECHO_MSG} "Epiphany-extensions also supports the following tunable option(s):"
	@${ECHO_MSG} "	WITH_OPENSP=yes		Enable support for OpenSP SGML validation"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
