# New ports collection makefile for:   gnucash-doc
# Date created:        Sun Feb 16 2003
# Whom:                Glenn Johnson <glennpj@charter.net>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	gnucash-docs
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	finance gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.gnucash.org/pub/gnucash/sources/stable/ \
		ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
		http://www.linas.org/pub/
MASTER_SITE_SUBDIR=	gnucash

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Documentation for gnucash

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper \
		yelp:${PORTSDIR}/x11/yelp

INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_GNOME=	libxml2 gnomehier
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

.include <bsd.port.mk>
