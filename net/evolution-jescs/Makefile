# New ports collection makefile for:	evolution-jescs
# Date created:				08 September 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	evolution-jescs
PORTVERSION=	2.4.1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Evolution Connector for Sun Java Enterprise System Calendar Server

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix evolutiondataserver
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
