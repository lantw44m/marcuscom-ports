# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$
#   $MCom$

PORTNAME=	hitori
PORTVERSION=	3.14.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Hitori

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool

USES=		gettext gmake pathfix pkgconfig tar:xz
USE_GNOME=	gtk30 intlhack librsvg2 libxml2:build
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
