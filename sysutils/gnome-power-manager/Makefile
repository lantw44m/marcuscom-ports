# New ports collection makefile for:	gnome-power-manager
# Date created:				03 May 2006
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-power-manager/Makefile,v 1.8 2006/07/27 13:53:39 marcus Exp $
#

PORTNAME=	gnome-power-manager
PORTVERSION=	2.15.90
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Power management system for the GNOME Desktop

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal \
		notify.2:${PORTSDIR}/devel/libnotify

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui libwnck \
		gnomedocutils
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-power-manager.schemas

.include <bsd.port.mk>
