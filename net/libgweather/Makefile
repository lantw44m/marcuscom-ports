# New ports collection makefile for:	libgweather
# Date created:				14th Jan 2008
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net/libgweather/Makefile,v 1.4 2008/01/19 23:10:36 mezz Exp $
#

PORTNAME=	libgweather
PORTVERSION=	2.21.2
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to accessing online weather informations

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gtk20 gnomevfs2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gweather.schemas

.include <bsd.port.mk>
