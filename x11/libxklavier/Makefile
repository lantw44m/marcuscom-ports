# New ports collection makefile for:	libxklavier
# Date created:				31 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD: ports/x11/libxklavier/Makefile,v 1.11 2004/02/04 05:09:47 marcus Exp $
#

PORTNAME=	libxklavier
PORTVERSION=	1.00
PORTEPOCH=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gswitchit

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An utility library to make XKB stuff easier

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gnomehack libxml2
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=13
CONFIGURE_ARGS=	--disable-doxygen
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
