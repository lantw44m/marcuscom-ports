# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/math/gcalctool3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gcalctool
PORTVERSION=	6.4.2.1
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME 3 calculator tool based on the old calctool for OpenWindows

CONFLICTS=	gcalctool-5.[0-9]*

BUILD_DEPENDS=	yelp-build:${PORTSDIR}/textproc/yelp-tools \
		itstool:${PORTSDIR}/textproc/itstool

LATEST_LINK=	gcalctool3
USE_XZ=	yes
USES=		bison gettext gmake pathfix
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix intlhack gconf2 gtk30 libxml2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gcalccmd.1 gcalctool.1
GLIB_SCHEMAS=	org.gnome.gcalctool.gschema.xml

.include <bsd.port.mk>
