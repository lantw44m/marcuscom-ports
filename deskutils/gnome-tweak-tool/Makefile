# New ports collection makefile for:	gnome-tweak-tool
# Date created:				17 March 2011
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-tweak-tool
PORTVERSION=	3.0.4
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Allows to tweak some hidden settings in GTK3/GNOME3

BUILD_DEPENDS=	gsettings-desktop-schemas>=0.1.0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gsettings-desktop-schemas>=0.1.0:${PORTSDIR}/devel/gsettings-desktop-schemas

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gconf2 pygobject
USE_PYTHON=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
