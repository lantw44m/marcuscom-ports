# New ports collection makefile for:	gnome-themes-extras
# Date Created:				12 June 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-themes/gnome-themes-extras/Makefile,v 1.16 2007/08/01 16:51:06 mezz Exp $
#

PORTNAME=	gnome-themes-extras
PORTVERSION=	2.20
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	More themes for the GNOME 2 desktop environment

BUILD_DEPENDS=	gtk-engines2>=2.11.0:${PORTSDIR}/x11-themes/gtk-engines2
RUN_DEPENDS=	gtk-engines2>=2.11.0:${PORTSDIR}/x11-themes/gtk-engines2

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_GNOME=	gnomehack libgnomeui intlhack
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
