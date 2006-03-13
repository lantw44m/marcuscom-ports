# New ports collection makefile for:	gtkhtml3
# Date created:				12 March 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/gtkhtml3/Makefile,v 1.73 2006/03/13 07:09:47 mezz Exp $
#

PORTNAME=	gtkhtml3
PORTVERSION=	3.9.92
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/3$//}/${PORTVERSION:C/^([0-9]+)\.([0-9]+).*/\1.\2/}
DISTNAME=	${PORTNAME:S/3$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lightweight HTML rendering/printing/editing engine

LIB_DEPENDS=	soup-2.2.8:${PORTSDIR}/devel/libsoup

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gail libgnomeui \
		libgnomeprintui ltverhack
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION="3.8"

.include <bsd.port.mk>
