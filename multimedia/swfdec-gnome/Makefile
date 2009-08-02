# Ports collection makefile for:	swfdec-gnome
# Date created:				2008 01 10
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/multimedia/swfdec-gnome/Makefile,v 1.21 2009/05/12 18:21:08 kwm Exp $
#

PORTNAME=	swfdec-gnome
PORTVERSION=	2.26.0
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Gtk flash player and thumbnailer

LIB_DEPENDS=	swfdec-0.8:${PORTSDIR}/graphics/swfdec

USE_GNOME=	gnomehack gnomeprefix gtk20 intlhack gconf2
USE_BZIP2=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	swfdec-thumbnailer.schemas

MAN1=		swfdec-player.1 swfdec-thumbnailer.1

post-patch:
	@${REINPLACE_CMD} -e 's|SWFDEC_MAJORMINOR=0.8|SWFDEC_MAJORMINOR=0.9|g' \
		${WRKSRC}/configure

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
