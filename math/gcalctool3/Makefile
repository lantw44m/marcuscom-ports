# New ports collection makefile for:	gcalctool
# Date created:				12 Jun 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/math/gcalctool/Makefile,v 1.140 2010/11/15 22:06:10 kwm Exp $
#

PORTNAME=	gcalctool
PORTVERSION=	5.91.5
CATEGORIES=	math gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME 3 calculator tool based on the old calctool for OpenWindows

USE_BZIP2=	yes
USE_BISON=	build
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2 gnomedocutils gtk30 libxml2
GNOME_DESKTOP_VERSION=	3
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gcalctool.1
GLIB_SCHEMAS=	org.gnome.gcalctool.gschema.xml

.include <bsd.port.mk>
