# New ports collection makefile for:	gnome-mount
# Date created:			04 June 2006
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-mount/Makefile,v 1.1 2006/06/04 17:40:15 marcus Exp $
#

PORTNAME=	gnome-mount
PORTVERSION=	0.3
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://people.freedesktop.org/~david/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A font-end to mount, umount, and eject using HAL

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal

USE_XLIB=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-mount.schemas

.include <bsd.port.mk>
