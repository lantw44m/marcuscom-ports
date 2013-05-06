# Created by: Jeremy Messenger <mezz@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/deskutils/gnome-tweak-tool/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	gnome-tweak-tool
PORTVERSION=	3.6.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Allows to tweak some hidden settings in GTK3 / GNOME3

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.4.0:${PORTSDIR}/devel/gsettings-desktop-schemas
RUN_DEPENDS=	gsettings-desktop-schemas>=3.4.0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		gnome-shell:${PORTSDIR}/x11/gnome-shell

USE_XZ=		yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gconf2 pygobject3
USE_PYTHON=	yes
USES=		gettext pathfix pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
