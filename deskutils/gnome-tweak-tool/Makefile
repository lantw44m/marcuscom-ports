# New ports collection makefile for:	gnome-tweak-tool
# Date created:				17 March 2011
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/deskutils/gnome-tweak-tool/Makefile,v 1.14 2011/11/19 10:10:26 kwm Exp $
#

PORTNAME=	gnome-tweak-tool
PORTVERSION=	3.4.0.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Allows to tweak some hidden settings in GTK3 / GNOME3

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.4.0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gsettings-desktop-schemas>=3.4.0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		gnome-shell:${PORTSDIR}/x11/gnome-shell

USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gconf2 pygobject3
USE_PYTHON=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
