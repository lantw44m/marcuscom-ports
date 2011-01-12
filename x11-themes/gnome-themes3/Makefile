# New ports collection makefile for:	gnome-themes
# Date Created:				05 October 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-themes/gnome-themes3/Makefile,v 1.1 2011/01/12 22:51:24 kwm Exp $
#

PORTNAME=	gnome-themes
PORTVERSION=	2.91.5
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of themes and icons for GNOME 3

BUILD_DEPENDS=	gtk-engines3>=2.15.0:${PORTSDIR}/x11-themes/gtk-engines3 \
		icon-naming-utils>=0.8.7:${PORTSDIR}/x11-themes/icon-naming-utils
RUN_DEPENDS=	gtk-engines3>=2.15.0:${PORTSDIR}/x11-themes/gtk-engines3

CONFLICTS=	clearlooks-metacity-0.*

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack gtk30
GNOME_DESKTOP_version=	3
CONFIGURE_ARGS=	--enable-icon-mapping
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
