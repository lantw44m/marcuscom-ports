# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/math/gcalctool/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gcalctool
PORTVERSION=	5.32.2
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME 2 calculator tool based on the old calctool for OpenWindows

CONFLICTS=	gcalctool-6.[0-9]*

USE_BZIP2=	yes
USES=		bison gettext gmake pathfix
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix intlhack gconf2 gnomedocutils gtk20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gcalctool.1
GLIB_SCHEMAS=	org.gnome.gcalctool.gschema.xml

.include <bsd.port.mk>
