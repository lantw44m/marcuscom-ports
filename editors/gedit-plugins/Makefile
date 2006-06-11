# New ports collection makefile for:	gedit-plugins
# Date created:				19 September 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	gedit-plugins
PORTVERSION=	2.15.3
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for GEdit 2

BUILD_DEPENDS=	gedit:${PORTSDIR}/editors/gedit \
		gucharmap:${PORTSDIR}/deskutils/gucharmap
RUN_DEPENDS=	gedit:${PORTSDIR}/editors/gedit \
		gucharmap:${PORTSDIR}/deskutils/gucharmap

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack pygnomedesktop
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gedit-show-tabbar-plugin.schemas

.include <bsd.port.mk>
