# New ports collection makefile for:	gnome-volume-manager
# Date created:			02 May 2006
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-volume-manager/Makefile,v 1.3 2006/06/08 01:48:53 ahze Exp $
#

PORTNAME=	gnome-volume-manager
PORTVERSION=	1.5.15
PORTREVISION=	3
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Automatically mount removable media, and more

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal \
		notify.2:${PORTSDIR}/devel/libnotify

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack nautilus2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-multiuser
GCONF_SCHEMAS=	gnome-volume-manager.schemas

.include <bsd.port.mk>
