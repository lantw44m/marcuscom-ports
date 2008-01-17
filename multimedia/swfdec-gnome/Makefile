# Ports collection makefile for:	swfdec-gnome
# Date created:				2008 01 10
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$

PORTNAME=	swfdec-gnome
PORTVERSION=	0.5.5
CATEGORIES=	multimedia
MASTER_SITES=	http://swfdec.freedesktop.org/download/swfdec-gnome/0.5/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Gtk flash player and thumbnailer

LIB_DEPENDS=	swfdec-0.5.5:${PORTSDIR}/graphics/swfdec

USE_GNOME=	gnomehack gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
GCONF_SCHEMAS=	swfdec-thumbnailer.schemas

.include <bsd.port.mk>
