# New ports collection makefile for:	gcalctool
# Date created:				12 Jun 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/math/gcalctool/Makefile,v 1.143 2011/04/30 20:43:21 mezz Exp $
#

PORTNAME=	gcalctool
PORTVERSION=	5.32.2
PORTEPOCH=	2
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME 2 calculator tool based on the old calctool for OpenWindows

CONFLICTS=	gcalctool-6.[0-9]*

USE_BZIP2=	yes
USE_BISON=	build
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2 gnomedocutils gtk20
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		gcalctool.1
GLIB_SCHEMAS=	org.gnome.gcalctool.gschema.xml

.include <bsd.port.mk>
